#ifndef _DataAccess_DepartmentData_H_
#define _DataAccess_DepartmentData_H_
#include <iostream>
#include <fstream>
#include <vector>

#include "../BusinessObject/Department.h"
#include "DataBusinessObject.h"
#include "../libs/json.hpp"

using namespace std;
using json = nlohmann::json;

class DepartmentData : public DataBusinessObject {
private:
    vector <Department> departmentArr;
    int maxID;
public:
    //Contructor function of DepartmentData
    DepartmentData();
    //GetmaxID() is a function that get the maximum ID of department data
    int GetMaxID();
    // PushBack(Department) is a function that push one department data in the back of _data vector and return maximun ID of the current _data vector
    //Get(int i) is a function that get the department data at i position of _data vector
    Department& Get(int);
    BusinessObject* GetPointer(int);
    int GetSize();
    void Add(Department&);
    void Edit(Department&, int);
    void Delete(int);
    void Read(string);
    int ExportToFile(string);
};    

#endif