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
public:
    ProjectData();

    //This function will point to the member of class we want to work with
    Project& Get(int);

    //This function will get the address of the member 
    //which we pointed by the function Get() above
    BusinessObject* GetPointer(int);

    //This fucntion will help us get the size of the vector at that time
    //after deleting or adding memeber
    int GetSize();

    //We modify our data directly by using these fucntions
    void Add(Project&);
    void Edit(Project&, int);
    void Delete(int);
    // Function will help us to read the data
    void Read(string);
    int ExportToFile(string);
};
#endif