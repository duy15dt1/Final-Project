#ifndef _DATAACCESS_DEPARTMENT_DATA_H_
#define _DATAACCESS_DEPARTMENT_DATA_H_
#include <vector>
#include "../BusinessObject/Department.h"
#include "DataBusinessObject.h"

class DepartmentData : public DataBusinessObject {
private:
    vector <Department> _departmentArr;
    int _maxId;
public:
    //Contructor function of DepartmentData
    DepartmentData();
    //GetMaxId() is a function that get the maximum ID of department data
    int GetMaxId();
    // PushBack(Department) is a function that push one department data in the back of _data vector and return maximun ID of the current _data vector
    //Get(int i) is a function that get the department data at i position of _data vector
    Department& Get(int );
    BusinessObject* GetPointer(int );
    int GetSize();
    void Add(Department&);
    void Edit(int );
    void Delete(int );
    void Read(string );
    int ExportToFile(string );
};    

#endif