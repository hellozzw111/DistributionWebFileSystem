#include "DataService/data_serv.pb.h"
#include "mprpcapplication.h"
#include "rpcprovider.h"
#include "DataServer/DataServer.h"

using namespace std;

class DataService : public dataserver::DataService {
public:
    void Add(::google::protobuf::RpcController* controller,
            const ::dataserver::AddRequest* request,
            ::dataserver::AddResponse* response,
            ::google::protobuf::Closure* done);
    void Get(::google::protobuf::RpcController* controller,
            const ::dataserver::GetRequest* request,
            ::dataserver::GetResponse* response,
            ::google::protobuf::Closure* done);
    void Del(::google::protobuf::RpcController* controller,
            const ::dataserver::DelRequest* request,
            ::dataserver::DelResponse* response,
            ::google::protobuf::Closure* done);
    void Dup(::google::protobuf::RpcController* controller,
             const ::dataserver::DupRequest* request,
             ::dataserver::DupResponse* reponse,
             ::google::protobuf::Closure* done);
    void ChangeMs(::google::protobuf::RpcController* controller,
                  const ::dataserver::ChangeMsRequest* request, 
                  ::dataserver::ChangeMsResponse* response,
                  ::google::protobuf::Closure* done);
    void DownGrade(::google::protobuf::RpcController* controller,
                   const ::dataserver::DownGradeRequest* request,
                   ::dataserver::DownGradeResponse* response,
                   ::google::protobuf::Closure* done);
    void UpGrade(::google::protobuf::RpcController* controller,
                  const ::dataserver::UpGradeRequest* request, 
                  ::dataserver::UpGradeResponse* response,
                  ::google::protobuf::Closure* done);
    void SyncFile(::google::protobuf::RpcController* controller,
                  const ::dataserver::SyncFileRequest* request, 
                  ::dataserver::SyncFileResponse* response,
                  ::google::protobuf::Closure* done);
};