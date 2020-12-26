#ifndef _DATAACCESS_PROJECT_DATA_H_
#define _DATAACCESS_PROJECT_DATA_H_
#include <vector>
#include "../BusinessObject/Project.h"
#include "DataBusinessObject.h"

class ProjectData : public DataBusinessObject{
private:
    vector<Project> _projectArr;
    int _maxId;
public:
    ProjectData();
    int GetMaxId();
    int PushBack(Project);
    Project& Get(int );
    int GetSize();
    void Add();
    void Edit(int );
    void Delete(int );
    void Read(string );
    int ExportToFile(string );
};
#endif