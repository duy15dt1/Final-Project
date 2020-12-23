#ifndef PROJECTDATA_H_
#define PROJECTDATA_H_
#include <vector>
#include "../BusinessObject/Project.h"

class ProjectData{
private:
    vector<Project> _data;
    int _maxId;
public:
    ProjectData();
    int GetMaxId();
    int PushBack(Project);
    Project Get(int i);
};

#endif