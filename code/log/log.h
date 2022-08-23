#pragma once
#include <string>
#include "producer.hpp"
#include "consumer.hpp"
// 定义宏 LOG_INFO("xxx %d %s", 20, "xxxx")
#define LOG_INFO(logmsgformat, ...) \
    do \
    {  \
        Logger &logger = Logger::GetInstance(); \
        char c[1024] = {0}; \
        snprintf(c, 1024, logmsgformat, ##__VA_ARGS__); \
        string s(c); \
        s = "INF" + s; \
        logger.Log(c); \
    } while(0) \

#define LOG_ERR(logmsgformat, ...) \
    do \
    {  \
        Logger &logger = Logger::GetInstance(); \
        char c[1024] = {0}; \
        snprintf(c, 1024, logmsgformat, ##__VA_ARGS__); \
        string s(c); \
        s = "ERR" + s; \
        logger.Log(c); \
    } while(0) \


// Mprpc框架提供的日志系统
class Logger
{
public:
    // 获取日志的单例
    static Logger& GetInstance();
    // 写日志
    void Log(std::string msg);
private:
    Producer producer_;
    Consumer consumer_;
    Logger(){
        consumer_.message();
    };
    Logger(const Logger&) = delete;
    Logger(Logger&&) = delete;
};