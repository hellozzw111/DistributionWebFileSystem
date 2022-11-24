#include "DataServer/DataServer.h"

DataServer* DataServer::getInstance(){
    if(instance == nullptr){
        unique_lock<mutex> lock(M_mutex);
        if(instance == nullptr){
            instance = new (nothrow) DataServer();
        }
    }
    return instance;
}
void DataServer::freeInstance(){
    if(instance != nullptr){
        unique_lock<mutex> lock(M_mutex);
        if(instance != nullptr){
            delete instance;
            instance = nullptr;
        }
    }
}
void DataServer::Add(const string& file_name, const string& contents){
    int prefix_path_name_length = prefix_name.size();
    string last_path_name = file_name.substr(prefix_path_name_length, file_name.size()-prefix_path_name_length);
    DataServerConfig* dsc_instance = DataServerConfig::getInstance();
    string true_path_name = dsc_instance->get_file_path() + last_path_name;
    bool item_type = true, object_type = true;
    if(file_name[true_path_name.size()-1] == '/') { // 添加目录 TODO: 如果是上传整个目录怎么办?
        string cmd("mkdir -p " + true_path_name);
        int ret = system(cmd.c_str());
        // 将结果添加到 change_buffer 列表中
        string change_item;
        item_type = true; // 表示Add -> false 表示Del
        object_type = false; // 表示目录，-> true 表示文件
        change_item.insert(0, string((char*)&item_type, 1));
        change_item.insert(1, string((char*)&object_type, 1));
        int true_path_name_len = true_path_name.size();
        change_item.insert(2, string((char*)&true_path_name_len, 4));
        change_item += true_path_name;
        change_buffer.push(change_item);
    } else { // 添加文件 
        ofstream out;
        out.open(true_path_name, ios::out);
        out<<contents;
        out.close();
        string change_item;
        item_type = true; // 表示Add -> false 表示Del
        object_type = true; // 表示目录，-> true 表示文件
        change_item.insert(0, string((char*)&item_type, 1));
        change_item.insert(1, string((char*)&object_type, 1));
        int true_path_name_len = true_path_name.size();
        change_item.insert(2, string((char*)&true_path_name_len, 4));
        change_item += true_path_name;
        int contents_len = contents.size();
        change_item.insert(6+true_path_name_len, string((char*)&contents_len, 4));
        change_item += contents;
        change_buffer.push(change_item);
    }
}
char* DataServer::Get(const string& file_name){
    int prefix_path_name_length = prefix_name.size();
    string last_path_name = file_name.substr(prefix_path_name_length, file_name.size()-prefix_path_name_length);
    DataServerConfig* dsc_instance = DataServerConfig::getInstance();
    string true_path_name = dsc_instance->get_file_path() + last_path_name;
    int srcFd = open(true_path_name.c_str(), O_RDONLY);
    int* mmRet = (int*)mmap(0, mmFileStat_.st_size, PROT_READ, MAP_PRIVATE, srcFd, 0);
    if(*mmRet == -1){
        std::cout<<"mmap error!"<<std::endl;
        return nullptr;
    }
    mmFile_ = (char*)mmRet;
    close(srcFd);
    return mmFile_;
}
void DataServer::UnmapFile() {
    if(mmFile_){
        munmap(mmFile_, mmFileStat_.st_size);
        mmFile_ = nullptr;
    }
}
void DataServer::Del(const string& file_name){ // TODO: 删除目录
    int prefix_path_name_length = prefix_name.size();
    string last_path_name = file_name.substr(prefix_path_name_length, file_name.size()-prefix_path_name_length);
    DataServerConfig* dsc_instance = DataServerConfig::getInstance();
    string true_path_name = dsc_instance->get_file_path() + last_path_name;
    bool item_type = true, object_type = true;
    if(true_path_name[true_path_name.size()-1] == '/') { // 删除目录
        DeleteFile(true_path_name.c_str());
        string change_item;
        item_type = false; // 表示Add -> false 表示Del
        object_type = false; // 表示目录，-> true 表示文件
        change_item.insert(0, string((char*)&item_type, 1));
        change_item.insert(1, string((char*)&object_type, 1));
        int true_path_name_len = true_path_name.size();
        change_item.insert(2, string((char*)&true_path_name_len, 4));
        change_item += true_path_name;
        change_buffer.push(change_item);
        return;
    }
    if(remove(true_path_name.c_str()) == 0){
        string change_item;
        item_type = false; // 表示Add -> false 表示Del
        object_type = true; // 表示目录，-> true 表示文件
        change_item.insert(0, string((char*)&item_type, 1));
        change_item.insert(1, string((char*)&object_type, 1));
        int true_path_name_len = true_path_name.size();
        change_item.insert(2, string((char*)&true_path_name_len, 4));
        change_item += true_path_name;
        change_buffer.push(change_item);
    }
}
void DataServer::Getfilepath(const char *path, const char *filename,  char *filepath)
{
    strcpy(filepath, path);
    if(filepath[strlen(path) - 1] != '/')
        strcat(filepath, "/");
    strcat(filepath, filename);
	printf("path is = %s\n",filepath);
}
 
void DataServer::DeleteFile(const char* path)
{
    DIR *dir;
    struct dirent *dirinfo;
    struct stat statbuf;
    char filepath[256] = {0};
    lstat(path, &statbuf);
    
    if (S_ISREG(statbuf.st_mode))//判断是否是常规文件
    {
        remove(path);
    }
    else if (S_ISDIR(statbuf.st_mode))//判断是否是目录
    {
        if ((dir = opendir(path)) == NULL)
            return;
        while ((dirinfo = readdir(dir)) != NULL)
        {
            Getfilepath(path, dirinfo->d_name, filepath);
            if (strcmp(dirinfo->d_name, ".") == 0 || strcmp(dirinfo->d_name, "..") == 0)//判断是否是特殊目录
            continue;
            DeleteFile(filepath);
            rmdir(filepath);
        }
        closedir(dir);
    }
}

void DataServer::sendContentsToSlaves() {
    while(start){
        if(!change_buffer.empty()) {
            unique_lock<mutex> lock(change_buffer_lock);
            const string& contents_ = change_buffer.front();
            change_buffer.pop();
            NameServerCli::getInstance()->sendDupContent(contents_.data());
        }
    }
}

void DataServer::UpGrade() {
    role = "master";
    for(int i=0;i<server_name.size();i++) {
        if(server_name[i] == '_') {
            server_name = server_name.substr(0, i+1);
        }
    }
}

void DataServer::DownGrade() {
    role = "slave";
    server_name = ChangeToSlaveName(server_name);
}