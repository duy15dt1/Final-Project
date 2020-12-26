#ifndef _DATAACCESS_EMPLOYEE_DATA_H_
#define _DATAACCESS_EMPLOYEE_DATA_H_
#include <vector>
#include "../BusinessObject/Employee.h"
#include "DataBusinessObject.h"
class EmployeeData : public DataBusinessObject {
private:
    vector<Employee> _employeeArr;
    int _maxId = 5;
public:
    EmployeeData();
    int GetMaxId();
    int PushBack(Employee);
    Employee& Get(int );
    int GetSize();
    void Add();
    void Edit(int );
    void Delete(int );
    void Read(string );
    int ExportToFile(string );
};
#endif