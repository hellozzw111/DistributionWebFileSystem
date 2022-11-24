#include <string>
#include <vector>
#include <mutex>
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include "config/DataServerConfig.hpp"
#include <thread>
#include <queue>
#include "DataService/data_serv.pb.h"
#include "src/include/mprpcchannel.h"
#include "src/include/mprpccontroller.h"
#include "nameserver_cli.h"

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
    void UpGrade();
    void DownGrade();
    void ChangeMs();
    void init() {
        mmFile_ = nullptr;
        mmFileStat_ = { 0 };
        start = true;
    }
    void UnmapFile();
private:
    bool start;
    string role; // "master" or "slave"    
    DataServer();
    static DataServer* instance;
    static mutex M_mutex;
    string prefix_name;
    string server_name;
    queue<string> change_buffer;
    int change_buffer_left, change_buffer_right;
    char* mmFile_;
    struct stat mmFileStat_;
    void Getfilepath(const char *path, const char *filename,  char *filepath);
    void DeleteFile(const char* path);
    void sendContentsToSlaves();
    string ChangeToSlaveName(string server_name);
    mutex change_buffer_lock;
};