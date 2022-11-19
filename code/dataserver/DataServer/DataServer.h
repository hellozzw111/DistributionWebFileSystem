#include <string>
#include <vector>
#include <mutex>

#include "config/DataServerConfig.hpp"

#define MAX_CHANGE_BUFFER 100;

using namespace std;


class DataServer {
public:
    DataServer(const DataServer& ds) = delete;
    DataServer& operator=(const DataServer& sd) = delete;
    static DataServer* getInstance();
    void freeInstance();
    void Add(const string& file_name, const string& contents);
    char* Get(const string& file_name);
    void Del(const string& file_name);
    void init() {
        mmFile_ = nullptr;
        mmFileStat_ = { 0 };
    }
    void UnmapFile();
private:    
    DataServer();
    static DataServer* instance;
    static mutex M_mutex;
    string prefix_name;
    string server_name;
    vector<string> change_buffer;
    int change_buffer_left, change_buffer_right;
    char* mmFile_;
    struct stat mmFileStat_;
    void Getfilepath(const char *path, const char *filename,  char *filepath);
    void DeleteFile(const char* path);
};