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
private:
    DataServer* dataserver_instance;
    void init_dataserver(){
        dataserver_instance = DataServer::getInstance();
    }
}