#ifndef _DATAACCESS_EMPLOYEE_DATA_H_
#define _DATAACCESS_EMPLOYEE_DATA_H_
#include <vector>
#include "../BusinessObject/Employee.h"
#include "DataBusinessObject.h"
#include <string.h> 
class EmployeeData : public DataBusinessObject {
private:
    vector<Employee> _employeeArr;
    int _maxId;
public:
    EmployeeData();
    Employee& Get(int );
    BusinessObject* GetPointer(int );
    void Add(Employee&);
    void Edit(Employee&, int );
    void Delete(int );
    void Read(string );
    int ExportToFile(string );
    int GetSize();
};
#endif