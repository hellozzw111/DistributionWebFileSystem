#ifndef __NAMESERVICE_H_
#define __NAMESERVICE_H_

#include <string>
#include <vector>
#include "name_serv.pb.h"
#include "mprpcapplication.h"
#include "rpcprovider.h"
#include "NodeManager/NodeManager.h"

using namespace std;

class NameService : public nameserver::NameService
{
public:
    bool HeartBeat(::google::protobuf::RpcController* controller,  // TODO: 删除change_files字段，改为nameserver接收后先改变NodeTree后再利用rpc发送给dataserver
                    const ::nameserver::HeartBeatRequest* request,
                    ::nameserver::HeartBeatResponse* response,
                    ::google::protobuf::Closure* done)
    {
        // receive rpc request from data servers
        string server_name = request->name();
        bool has_change = request->has_change();
        string host = request->host();
        const vector<string> change_files = request->change_files();
        if(has_change){ NodeManager::getInstance()->UpdateNodeTree(name, host, change_files); }
        response->set_success = true;
        done->Run();
    }
};

#endif