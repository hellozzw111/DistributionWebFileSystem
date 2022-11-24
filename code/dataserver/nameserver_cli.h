// 两种类型的 dataserver 1. master  2. slave
// 启动rpc服务
#include <string>
#include "mprpcapplication.h"
#include "rpcprovider.h"
#include <vector>
#include <unordered_map>

using namespace std;

struct nameserverstatus {
    string name;
    string ip;
    int port;
    string role;
    int score;
};

class NameServerCli {
public:
    NameServerCli(const NameServerCli& ns) = delete;
    NameServerCli operator=(const NameServerCli& ns) = delete;
    static NameServerCli* getInstance();
    void initNameServerCli(string name, string ip, int port, string role) {
        this->name = name;
        this->ip = ip;
        this->port = port;
        this->role = role;
        initRpcService();
    }
    void initRpcService();
    void initTimer();
    void sendHeartBeat();
    void sendDupContent(const char* content);
private:
    NameServerCli();
    static NameServerCli* instance;
    static mutex M_mutex;
    string name;
    string ip;
    int port;
    string role;
    unordered_map<string, nameserverstatus> slaves;
    dataserver::DataService_Stub stub;
};