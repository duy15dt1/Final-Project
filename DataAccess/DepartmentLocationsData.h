#ifndef _DataAccess_DepartmentLocationsData_H_
#define _DataAccess_DepartmentLocationsData_H_
#include <iostream>
#include <fstream>
#include <vector>

#include "../BusinessObject/DepartmentLocations.h"
#include "DataBusinessObject.h"
#include "../libs/json.hpp"

using namespace std;
using json = nlohmann::json;

class DepartmentLocationsData : public DataBusinessObject {
private:
    vector<DepartmentLocations> deptlocationArr;
public:
    DepartmentLocationsData();

    //This function will point to the member of class we want to work with
    DepartmentLocations& Get(int i);

    //This function will get the address of the member 
    //which we pointed by the function Get() above
    BusinessObject* GetPointer(int);

    //This fucntion will help us get the size of the vector at that time
    //after deleting or adding memeber
    int GetSize();

    //We modify our data directly by using these fucntions
    void Add(DepartmentLocations&);
    void Edit(DepartmentLocations&, int);
    void Delete(int);
    // Function will help us to read the data
    void Read(string);
    int ExportToFile(string);
};

#endif