// 用来管理注册的dataserver的类，包含主从状态和数据保存情况
#include <vector>
#include <string>
#include <unordered_map>
#include <muduo/net/TcpConnection.h>
#include <chrono>
#include <mutex>
#include <set>
#include "rpc/src/include/mprpcapplication.h"
#include "DataService/data_serv.pb.h"

const std::chrono::seconds time_interval(1);

using namespace std;

struct status {
    string name;
    string role;
    string ip;
    int port;
    int score;
    chrono::_V2::system_clock::time_point last_heartbeat_time;
};

class ServerManager {
public:
    ServerManager(const ServerManager& sm) = delete;
    ServerManager& operator=(const ServerManager& sm) = delete;
    static ServerManager* getInstance();
    static void deleteInstance();
    void checkHeartBeat();
    void dealDisconnect(status& obj);
    void upgradeServer(status& slave);
    void updataStatus(status& obj, int score);
    status& getStatus(string server_name);
    unordered_map<string, set<string>>& getMasterSlaves() { return master_slaves; }
private:
    static ServerManager* instance;
    static mutex M_mutex;
    ServerManager();
    unordered_map<string, muduo::net::TcpConnectionPtr> masters;
    unordered_map<string, muduo::net::TcpConnectionPtr> slaves;
    unordered_map<string, set<string>> master_slaves;
    unordered_map<string, status> server_status;
};