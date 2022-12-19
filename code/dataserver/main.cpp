#include <iostream>
#include "ServerManager/ServerManager.h"
#include "nameserver_cli.h"
#include "yaml-cpp/yaml.h"
#include <string>

void timeFunc(int sig){
    ServerManager::getInstance()->checkHeartBeat();
}

int main(int argc, char** args) {
    YAML::Node config = YAML::LoadFile("config.yaml");
    std::string name = config["name"].as<std::string>();
    std::string prefix_name = config["prefix_name"].as<std::string>();
    std::string role = config["role"].as<std::string>();
    YAML::Node ip_host = config["ip"][0];
    YAML::Node ip_zookeeper = config["ip"][0];
    YAML::Node port_host = config["port"][0];
    YAML::Node port_zookeeper = config["port"][0];
    NameServerCli::getInstance()->initNameServerCli(role, name, prefix_name, ip_host["host"].as<std::string>(), port_host["host"].as<int>(), ip_zookeeper["zookeeper"].as<std::string>(), port_zookeeper["zookeeper"].as<int>());
} 
  