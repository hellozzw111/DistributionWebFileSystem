#include "log.h"
#include <time.h>
#include <iostream>

// 获取日志的单例
Logger& Logger::GetInstance()
{
    static Logger logger;
    return logger;
}

// 写日志， 把日志信息写入lockqueue缓冲区当中
void Logger::Log(std::string msg)
{
    producer_.message(msg);
}