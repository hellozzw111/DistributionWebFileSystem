#ifndef __NAMESERVICE_H_
#define __NAMESERVICE_H_

#include <string>
#include <vector>
#include "name_serv.pb.h"
#include "mprpcapplication.h"
#include "rpcprovider.h"
#include "NodeManager/NodeManager.h"
#include "ServerManager/ServerManager.h"

using namespace std;

class NameService : public nameserver::NameService
{
public:
    void HeartBeat(::google::protobuf::RpcController* controller,  // TODO: 删除change_files字段，改为nameserver接收后先改变NodeTree后再利用rpc发送给dataserver
                    const ::nameserver::HeartBeatRequest* request,
                    ::nameserver::HeartBeatResponse* response,
                    ::google::protobuf::Closure* done)
    {
        // receive rpc request from data servers
        string server_name = request->name();
        string host = request->host();
        int port = request->port();
        string role = request->role();
        auto scores = request->score();
        if(role == "master") {
            int loc = 0;
            unordered_map<string, set<string>> master_slaves = ServerManager::getInstance()->getMasterSlaves();
            if(master_slaves.find(server_name) == master_slaves.end()) { 
                // DownGrade
                dataserver::DataService_Stub stub(new MprpcChannel());
                dataserver::DownGradeRequest request;
                dataserver::DownGradeResponse response;
                MprpcController controller;
                stub.DownGrade(&controller, &request, &response, nullptr);
                if(response.success()) {
                    string name_ = response.name();
                    string master_name_ = "";
                    for(int i=0;i<name_.size();i++){
                        if(name_[i] == '_'){
                            master_name_ = name_.substr(0, i+1);
                        }
                    }
                    master_slaves[master_name_].insert(name_);
                    status tmp_status = {name_, "slave", host, port, 0, chrono::system_clock::now()};
                }
            }
            for(auto it = master_slaves[server_name].begin();it!=master_slaves[server_name].end();it++){
                auto status = ServerManager::getInstance()->getStatus(*it);
                status.score = scores[loc++];
                status.last_heartbeat_time = chrono::system_clock::now();
            }
        }
    }
};

#endif