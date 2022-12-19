#include <string>
#include <vector>
#include "DataService/data_serv.pb.h"

class DataServer_Base {
public:
    virtual void Add(const std::string& file_name, const std::string& contents) = 0;
    virtual char* Get(const std::string& file_name) = 0;
    virtual void Del(const std::string& file_name) = 0;
    virtual void UpGrade() = 0;
    virtual const std::string& DownGrade() = 0;
    virtual void ChangeMs() = 0;
    virtual void SyncFile(std::vector<std::string> files_name, std::vector<::dataserver::Directory> directorys_name) = 0;
};