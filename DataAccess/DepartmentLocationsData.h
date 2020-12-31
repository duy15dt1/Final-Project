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
    int maxID;
public:
    DepartmentLocationsData();
    int GetMaxID();
    DepartmentLocations& Get(int i);
    BusinessObject* GetPointer(int);
    int GetSize();
    void Add(DepartmentLocations&);
    void Edit(DepartmentLocations&, int);
    void Delete(int);
    void Read(string);
    int ExportToFile(string);
};

#endif