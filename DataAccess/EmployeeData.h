#ifndef _DATAACCESS_EMPLOYEE_DATA_H_
#define _DATAACCESS_EMPLOYEE_DATA_H_
#include <vector>
#include "../BusinessObject/Employee.h"

class EmployeeData{
private:
    vector<Employee> _employeeArr;
    int _maxId;
public:
    EmployeeData();
    int GetMaxId();
    int PushBack(Employee);
    Employee& Get(int i);
    void Erase(int i);
    int GetSize();
};
#endif