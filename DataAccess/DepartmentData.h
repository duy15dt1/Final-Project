#ifndef _DATAACCESS_DEPARTMENT_DATA_H_
#define _DATAACCESS_DEPARTMENT_DATA_H_
#include <vector>
#include "../BusinessObject/Department.h"

using namespace std;
class DepartmentData{
    private:
        vector <Department> _data;
        int _maxId;
    public:
    //Contructor function of DepartmentData
    DepartmentData();
    //GetMaxId() is a function that get the maximum ID of department data
    int GetMaxId();
    // PushBack(Department) is a function that push one department data in the back of _data vector and return maximun ID of the current _data vector
    int PushBack(Department);
    //Get(int i) is a function that get the department data at i position of _data vector
    Department Get(int i);
};    

#endif