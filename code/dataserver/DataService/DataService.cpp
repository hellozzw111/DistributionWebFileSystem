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
        dataserver_instance->Add(file_name, contents);
        response->set_success(true);
        done->Run();
    } else { // 传入目录
        // 新建单个目录
        dataserver_instance->Add(file_name, contents);
        // TODO: 传入整个目录（包含其他文件或者目录）
    }
}
void DataService::Get(::google::protobuf::RpcController* controller,
            const ::dataserver::GetRequest* request,
            ::dataserver::GetResponse* response,
            ::google::protobuf::Closure* done)
{ 
    const string file_name = request->file_name();
    const char* contents = dataserver_instance->Get(file_name);
    response->set_success(true);
    response->set_contents(string(contents, strlen(contents)));
    done->Run();
    dataserver_instance->UnmapFile();
}
void DataService::Del(::google::protobuf::RpcController* controller,
            const ::dataserver::DelRequest* request,
            ::dataserver::DelResponse* response,
            ::google::protobuf::Closure* done)
{
    const string file_name = request->file_name();
    dataserver_instance->Del(file_name);
    response->set_success(true);
    done->Run();
}