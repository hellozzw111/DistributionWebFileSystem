#include "NodeManager/NodeManager.h"

NodeManager* NodeManager::instance = nullptr;
NodeManager* NodeManager::getInstance(){
    if(instance == nullptr){
        unique_lock<mutex> lock(m_Mutex);
        if(instance == nullptr){
            instance = new (nothrow) NodeManager();
        }
    }
    return instance;
}
void NodeManager::freeInstance(){
    unique_lock<mutex> lock(m_Mutex);
    if(instance){
        delete instance;
        instance = nullptr;
    }
}
void NodeManager::InitNodeManager(){
    Node* root = new Node;
    root->file_name = "/";
    root->is_file = false;
    root->parent = nullptr;
    root->is_new_dataserver = false;
    root->host = "124.220.24.66:1316";
    NodeTree = root;
}
void NodeManager::UpdateNodeTree(string name, string host, vector<string> change_files, vector<bool> add){
    string cur_path_name = "/";
    Node* cur_path_node = NodeTree;
    while(cur_path_name != name){ // first
        int left = cur_path_name.size(), right = 0;
        string next_file = "";
        for(int i=left;i<name.size();i++){
            if(name[i] == '/'){
                right = i;
                next_file = name.substr(left, right-left);
            }
        }
        for(auto it = cur_path_node->childs.begin();it!=cur_path_node->childs.end();it++){
            if((*it)->file_name == next_file){
                cur_path_name += next_file;
                cur_path_name += "/";
                cur_path_node = *it;
            }
        }
    }
    for(int i=0;i<change_files.size();i++){
        UpdateNodeFile(change_files[i], add[i], cur_path_node);
    }
}
void NodeManager::UpdateNodeFile(string file_name, bool add, Node* cur_node){
    int len = cur_node->file_name.size();
    int left = len, right = len;
    string tmp_node_name;
    while(right < file_name.size()){
        if(file_name[right] == '/'){
            tmp_node_name = file_name.substr(left, right-left);
            for(auto it = cur_node->childs.begin();it<cur_node->childs.end();it++){
                if((*it)->file_name == tmp_node_name){
                    cur_node = *it;
                    left = right+1;
                    right++;
                }
            }
        }
    }
    if(left == right){
        // 改变的是一个目录 TODO: 判断是一个新的服务器Node，断开连接后再删除节点
        if(add){
            Node* new_node = new Node;
            new_node->file_name = tmp_node_name;
            new_node->is_file = false;
            new_node->is_new_dataserver = false;
            new_node->parent = cur_node;
            cur_node->childs.push_back(new_node);
        }else{
            Node* cur_node_parent = cur_node->parent;
            // 递归删除目录下所有的节点
            deleteNodeFile(cur_node);
            cur_node_parent = nullptr;
        }
    }
}
void NodeManager::deleteNodeFile(Node* cur_node){
    if(cur_node->is_file){
        delete cur_node;
    }else{
        for(auto it = cur_node->childs.begin();it<cur_node->childs.end();it++){
            deleteNodeFile(*it);
        }
    }
}
Node* NodeManager::getNodeTree() {
    return NodeTree;
}