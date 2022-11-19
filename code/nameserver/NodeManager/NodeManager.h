#ifndef  __NODEMANAGER_H_
#define  __NODEMANAGER_H_

#include <string>
#include <vector>
#include <mutex>

using namespace std;

struct Node{
    string file_name;
    bool is_file;
    Node* parent;
    vector<Node*> childs;
    bool is_new_dataserver;
    string host;
};

class NodeManager {
public:
    NodeManager(const NodeManager& nm) = delete;
    const NodeManager &operator=(const NodeManager& nm) = delete;
    static NodeManager* getInstance();
    static void freeInstance();
    void BuildNodeTree();
    void UpdateNodeTree(string name, string host, vector<string> change_files, vector<bool> add);
    void UpdateNodeFile(string file_name, bool add, Node* data_server_node);
    void deleteNodeFile(Node* cur_node);
    Node* getNodeTree(){ return NodeTree; }
private:
    NodeManager();
    void InitNodeManager();
    Node* NodeTree; // "/"
    static NodeManager* instance;
    static mutex m_Mutex;
};


#endif