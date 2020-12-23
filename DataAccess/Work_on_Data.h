#ifndef _DATAACCESS_WORK_ON_DATA_H_
#define _DATAACCESS_WORK_ON_DATA_H_
#include <vector>
#include "../BusinessObject/Work_on.h"

using namespace std;
class Work_on_Data{
    private:
        vector <Work_on_Data> _data;
        int _maxId;
    public:
    //Contructor function of DepartmentData
    Work_on_Data();
    //GetMaxId() is a function that get the maximum ID of department data
    int GetMaxId();
    // PushBack(Department) is a function that push one department data in the back of _data vector and return maximun ID of the current _data vector
    int PushBack(Work_on);
    //Get(int i) is a function that get the department data at i position of _data vector
    Work_on Get(int i);
};    

#endif