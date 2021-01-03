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

    //maxID is the maximum number of member of class Employee
    //after adding, deleting
    int maxID;
public:
    EmployeeData();
    int GetMaxID();

    //This function will point to the member of class we want to work with
    Employee& Get(int);

    //This function will get the address of the member 
    //which we pointed by the function Get() above
    BusinessObject* GetPointer(int);

    //This fucntion will help us get the size of the vector at that time
    //after deleting or adding memeber
    int GetSize();

    //We modify our data directly by using these fucntions
    void Add(Employee&);
    void Edit(Employee&, int);
    void Delete(int);
    void Read(string);
    int ExportToFile(string);
    
};
#endif