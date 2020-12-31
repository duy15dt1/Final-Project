#ifndef _DATAACCESS_EMPLOYEE_DATA_H_
#define _DATAACCESS_EMPLOYEE_DATA_H_
#include <iostream>
#include <fstream>
#include <vector>

#include "../BusinessObject/Employee.h"
#include "DataBusinessObject.h"

using namespace std;
using json = nlohmann::json;

class EmployeeData : public DataBusinessObject {
private:
    vector<Employee> employeeArr;
    int maxID;
public:
    EmployeeData();
    int GetMaxID();
    Employee& Get(int);
    BusinessObject* GetPointer(int);
    int GetSize();
    void Add(Employee&);
    void Edit(Employee&, int);
    void Delete(int);
    void Read(string);
    int ExportToFile(string);
    
};
#endif