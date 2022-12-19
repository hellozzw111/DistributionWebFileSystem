// 两种类型的 dataserver 1. master  2. slave
// 启动rpc服务
#include <string>
#include <vector>
#include <unordered_map>
#include <time.h>
#include <signal.h>

#include "mprpcapplication.h"
#include "rpcprovider.h"
#include "DataService/DataService.h"
#include "DataService/data_serv.pb.h"
#include "NameService/name_serv.pb.h"
#include "DataServer/DataServer.h"

class DataServer;

using namespace std;

struct nameserverstatus {
    std::string name;
    std::string ip;
    int port;
    std::string role;
    int score;
};

class NameServerCli {
public:
    NameServerCli(const NameServerCli& ns) = delete;
    NameServerCli operator=(const NameServerCli& ns) = delete;
    static NameServerCli* getInstance();
    void initNameServerCli(std::string role, std::string name, std::string prefix_name, std::string ip_host, int port_host, std::string ip_zookeeper, int port_zookeeper) {
        this->name = name;
        this->prefix_name = prefix_name;
        this->ip = ip;
        this->port = port;
        this->role = role;
        this->zookeeper_ip = zookeeper_ip;
        this->zookeeper_port = zookeeper_port;
        initRpcService(name, role, ip, port, zookeeper_ip, zookeeper_port);
        initTimer();
    }
    void initRpcService(std::string name, std::string role, std::string ip, int port, std::string zookeeper_ip, int zookeeper_port);
    void initTimer();
    void sendHeartBeat();
    void sendDupContent(const char* content);
    void Add(std::string file_name, std::string contents) {
        DataServer::getInstance()->Add(file_name, contents);
    }
    const char* Get(std::string) {
        return DataServer::getInstance()->Get(file_name);
    }
    void UnmapFile() {
        DataServer::getInstance()->UnmapFile();
    }
    void Del(std::string file_name) {
        DataServer::getInstance()->Del(file_name);
    }
    void ChangeMs() {
        DataServer::getInstance()->ChangeMs();
    }
    void UpGrade() {
        DataServer::getInstance()->UpGrade(s);
    }
    const std::string DownGrade() {
        return DataServer::getInstance()->DownGrade();
    }
    void SyncFile(std::string, std::vector<::dataserver::Directory>) {
        
    }
private:
    NameServerCli();
    static NameServerCli* instance;
    static mutex M_mutex;
    std::string name;
    std::string prefix_name;
    std::string ip;
    int port;
    std::string role;
    std::string zookeeper_ip;
    int zookeeper_port;
    unordered_map<std::string, nameserverstatus> slaves;
    dataserver::DataService_Stub stub;
};