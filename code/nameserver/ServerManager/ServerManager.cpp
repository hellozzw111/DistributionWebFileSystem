#include "ServerManager/ServerManager.h"

ServerManager* ServerManager::getInstance(){
    if(instance == nullptr){
        unique_lock<mutex> lock(M_mutex);
        if(instance == nullptr){
            instance = new (nothrow) ServerManager();
        }
    }
    return instance;
}

void ServerManager::updataStatus(status& obj, int score) {
    obj.score = score;
}

status& ServerManager::getStatus(string server_name) {
    return server_status.find(server_name)->second;
}

void ServerManager::checkHeartBeat(){
    auto now = chrono::system_clock::now();
    for(auto it = server_status.begin();it!=server_status.end();it++){
        if(chrono::duration_cast<chrono::seconds>(now - (it->second).last_heartbeat_time) <= chrono::seconds(0)){
            dealDisconnect(it->second);
        }
    }

}

void ServerManager::dealDisconnect(status& obj){
    string server_name = obj.name;
    string role = obj.role;
    if(role == "master") {  // 主服务器断开连接
        set<string> slaves_ = master_slaves[obj.name];
        status best_slave = {0};
        for(auto it = slaves_.begin();it!=slaves_.end();it++){
            status temp_slave = server_status[*it];
            if(temp_slave.score > best_slave.score){
                best_slave = temp_slave;
            }
        }
        muduo::net::TcpConnectionPtr best_slave_conn = slaves[best_slave.name];
        dataserver::DataService_Stub stub(new MprpcChannel());
        dataserver::ChangeMsRequest request;
        dataserver::ChangeMsResponse response;
        auto slaves_ = master_slaves[server_name];
        for(auto it=slaves_.begin();it!=slaves_.end();it++){
            if(*it != best_slave.name){
                request.add_slave_name(*it);
            }
        }
        MprpcController controller;
        stub.ChangeMs(&controller, &request, &response, nullptr);
        if(response.success()) {
            slaves_.erase(best_slave.name);
            master_slaves.erase(master_slaves.find(server_name));
            master_slaves[best_slave.name] = slaves_;
        }
        // 发送upgradeRPC消息
    } else { // 从服务器断开连接
        auto it = slaves.find(server_name);
        it->second->shutdown();
        slaves.erase(it);
        string master_name = server_name.substr(0, server_name.size()-6);
        auto master_it = master_slaves.find(master_name);
        for(int i=0;i<master_it->second.size();i++){
            master_it->second.erase(master_it->second.find(server_name));
        }
        server_status.erase(server_status.find(server_name));
    }
}