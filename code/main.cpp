/*
 * @Author       : mark
 * @Date         : 2020-06-18
 * @copyleft Apache 2.0
 */ 
#include "server/webserver.h"
#include "ServerManager/ServerManager.h"
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>

void timeFunc(int sig){
    ServerManager::getInstance()->checkHeartBeat();
}

int main() {
    
    /* 守护进程 后台运行 */
    //daemon(1, 0); 

    WebServer server(
        1316, 3, 60000, false,             /* 端口 ET模式 timeoutMs 优雅退出  */
        3306, "root", "123456", "yourdb", /* Mysql配置 */
        12, 6, true, 1, 1024);             /* 连接池数量 线程池数量 日志开关 日志等级 日志异步队列容量 */
    server.Start();

    struct itimerval itv;
	//信号处理
	if (SIG_ERR == signal(SIGALRM, timeFunc)) {
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
  