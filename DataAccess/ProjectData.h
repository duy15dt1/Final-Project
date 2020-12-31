#ifndef _DATAACCESS_PROJECT_DATA_H_
#define _DATAACCESS_PROJECT_DATA_H_
#include <iostream>
#include <fstream>
#include <vector>

#include "../BusinessObject/Project.h"
#include "DataBusinessObject.h"
#include "../libs/json.hpp"

using namespace std;
using json = nlohmann::json;

class ProjectData : public DataBusinessObject {
private:
    vector<Project> projectArr;
    int maxID;
public:
    ProjectData();
    int GetMaxID();
    Project& Get(int);
    BusinessObject* GetPointer(int);
    int GetSize();
    void Add(Project&);
    void Edit(Project&, int);
    void Delete(int);
    void Read(string);
    int ExportToFile(string);
};
#endif