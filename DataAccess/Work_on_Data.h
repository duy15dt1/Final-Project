#ifndef _DATAACCESS_WORK_ON_DATA_H_
#define _DATAACCESS_WORK_ON_DATA_H_
#include <vector>
#include "../BusinessObject/Work_on.h"

using namespace std;
class Work_on_Data{
    private:
        vector <Work_on> _data;
        int _maxId;
    public:
    //Contructor function of Work_on_Data
    Work_on_Data();
    //GetMaxId() is a function that get the maximum ID of Work_on data
    int GetMaxId();
    // PushBack(Work_on) is a function that push one Work_on data in the back of _data vector and return maximun ID of the current _data vector
    int PushBack(Work_on);
    //Get(int i) is a function that get the Work_on data at i position of _data vector
    Work_on Get(int i);
};    

#endif