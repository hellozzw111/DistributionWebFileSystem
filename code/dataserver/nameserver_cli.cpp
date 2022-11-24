#include "nameserver_cli.h"
#include "DataService/DataService.h"
#include "DataService/data_serv.pb.h"
#include "NameService/name_serv.pb.h"

void NameServerCli::initRpcService() {
    MprpcApplication::Init(argc, argv);

    // provider是一个rpc网络服务对象。把UserService对象发布到rpc节点上
    RpcProvider provider;
    provider.NotifyService(new DataService());

    // 启动一个rpc服务发布节点   Run以后，进程进入阻塞状态，等待远程的rpc调用请求
    provider.Run();
}

void NameServerCli::sendHeartBeat() {
    nameserver::FiendServiceRpc_Stub stub(new MprpcChannel()); // MprpcChannel添加参数用来判断选择那个对象进行发送
    // rpc方法的请求参数
    nameserver::HeartBeatRequest request;
    request.set_name(name);
    request.set_ip(ip);
    request.set_port(port);
    request.set_role(role);
    if(role == "master"){
        vector<uint32_t> slaves_score;
        for(auto it=slaves.begin();it!=slaves.end();i++){
            slaves_score.push_back((*it).second.score);
        }
        request.set_score(slaves_score);
    }
    // rpc方法的响应
    fixbug::GetFriendsListResponse response;
    // 发起rpc方法的调用  同步的rpc调用过程  MprpcChannel::callmethod
    MprpcController controller;
    stub.HeartBeat(&controller, &request, &response, nullptr); // RpcChannel->RpcChannel::callMethod 集中来做所有rpc方法调用的参数序列化和网络发送

    // 一次rpc调用完成，读调用的结果
    if (controller.Failed())
    {
        std::cout << controller.ErrorText() << std::endl;
    }
    else
    {}
}

void NameServerCli::initTimer() {
    struct itimerval itv;
	//信号处理
	if (SIG_ERR == signal(SIGALRM, sendHeartBeat)) {
		perror("signal");
		return -1;
	}
	//设置定时时长: 0.5ms
	itv.it_interval.tv_sec  = 0;
	itv.it_interval.tv_usec = 500;
	//设置启动时间: 1秒后启动
	itv.it_value.tv_sec  = 1;
	itv.it_value.tv_usec = 0;
	//设置定时器
	if (-1 == setitimer(ITIMER_REAL, &itv, NULL)) {

	}
}
NameServerCli* NameServerCli::getInstance() {
    if(instance == nullptr){
        unique_lock<mutex> lock(M_mutex);
        if(instance == nullptr){
            instance = new (nothrow) NameServerCli();
        }
    }
    return instance;
}
void NameServerCli::sendDupContent(const char* contents_) {
    auto it = slaves.begin();
    for(int i=0;i<slaves.size();i++) {
        dataserver::DupRequest request;
        dataserver::DupResponse response;
        request.set_contents({contents_, strlen(contents_)});
        MprpcController controller;
        stub.Dup(&controller, &request, &response, nullptr);
        if(response.success) {
            it->second.score++;
        }
        it++;
    }
}