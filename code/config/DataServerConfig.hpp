#include "yaml-cpp/yaml.h"
#include <string>
#include <mutex>

using namespace std;

#define options_key(x) #x

class DataServerConfig {
public:
    DataServerConfig(const DataServerConfig& dsc) = delete;
    DataServerConfig& operator=(const DataServerConfig& dsc) = delete;
    void load_yaml_config(string yaml_path){
        YAML::Node configures = YAML::LoadFile(yaml_path);
        ip = configures[options_key(ip)].as<decltype(ip)>();
        port = configures[options_key(port)].as<decltype(port)>();
        file_path = configures[options_key(file_path)].as<decltype(file_path)>();
        server_name = configures[options_key(server_name)].as<decltype(server_name)>();
    }
    static DataServerConfig* getInstance(){
        if(instance == nullptr){
            unique_lock<mutex> lock(M_mutex);
            if(instance == nullptr){
                instance = new (nothrow) DataServerConfig();
            }
        }
        return instance;
    }
    void freeInstance(){
        if(instance != nullptr){
            unique_lock<mutex> lock(M_mutex);
            if(instance != nullptr){
                delete instance;
                instance = nullptr;
            }
        }
    }
    string get_ip(){ return ip; }
    string get_port(){ return port; }
    string get_file_path(){ return file_path; }
    string get_server_name(){ return server_name; }
private:
    DataServerConfig() {};
    static DataServerConfig* instance;
    static mutex M_mutex;
    string ip;
    string port;
    string file_path;
    string server_name;
};

