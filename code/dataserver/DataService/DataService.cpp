#include "DataService/DataService.h"
#include <fstream>
#include <iostream>
#include <string>

void DataService::Add(::google::protobuf::RpcController* controller,
            const ::dataserver::AddRequest* request,
            ::dataserver::AddResponse* response,
            ::google::protobuf::Closure* done) {
    const string file_name = request->file_name();
    const string contents = request->contents();
    int len = file_name.size();
    bool isfile_ = true;
    if(file_name[len-1] == '/')
        isfile_ = false;
    if(isfile_) { // 传入文件
        DataServer::getInstance()->Add(file_name, contents);
        response->set_success(true);
        done->Run();
    } else { // 传入目录
        // 新建单个目录
        DataServer::getInstance()->Add(file_name, contents);
        // TODO: 传入整个目录（包含其他文件或者目录）
    }
}
void DataService::Get(::google::protobuf::RpcController* controller,
            const ::dataserver::GetRequest* request,
            ::dataserver::GetResponse* response,
            ::google::protobuf::Closure* done)
{ 
    const string file_name = request->file_name();
    const char* contents = DataServer::getInstance()->Get(file_name);
    response->set_success(true);
    response->set_contents(string(contents, strlen(contents)));
    done->Run();
    DataServer::getInstance()->UnmapFile();
}
void DataService::Del(::google::protobuf::RpcController* controller,
            const ::dataserver::DelRequest* request,
            ::dataserver::DelResponse* response,
            ::google::protobuf::Closure* done)
{
    const string file_name = request->file_name();
    DataServer::getInstance()->Del(file_name);
    response->set_success(true);
    done->Run();
}

void DataService::Dup(::google::protobuf::RpcController* controller,
             const ::dataserver::DupRequest* request,
             ::dataserver::DupResponse* reponse,
             ::google::protobuf::Closure* done) {
    const string contents = request->contents();
    //解析contents
    int len = contents.size();
    bool item_type = false, object_type = false;
    contents.copy((char*)&item_type, 1, 0);
    contents.copy((char*)&object_type, 1, 1);
    int file_path_len = 0;
    contents.copy((char*)&file_path_len, 4, 2);
    string file_path = contents.substr(6, file_path_len);
    string file_contents = "";
    if(item_type){ // true表示Add，false表示Del
        if(object_type){ //true表示文件，false表示目录
            int file_content_len = 0;
            contents.copy((char*)&file_content_len, 4, 6+file_path_len);
            file_contents = contents.substr(10+file_path_len, file_content_len);
            DataServer::getInstance()->Add(file_path, file_contents);
        }
    }else{
        DataServer::getInstance()->Del(file_path);
    }
}

void ChangeMs(::google::protobuf::RpcController* controller,
                  const ::dataserver::ChangeMsRequest* request, 
                  ::dataserver::ChangeMsResponse* response,
                  ::google::protobuf::Closure* done) {
    
}
void DownGrade(::google::protobuf::RpcController* controller,
                const ::dataserver::DownGradeRequest* request,
                ::dataserver::DownGradeResponse* response,
                ::google::protobuf::Closure* done) {
    
}
void UpGrade(::google::protobuf::RpcController* controller,
                const ::dataserver::UpGradeRequest* request, 
                ::dataserver::UpGradeResponse* response,
                ::google::protobuf::Closure* done) {
    
}