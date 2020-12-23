#ifndef _DATAACCESS_DEPENDENT_DATA_H_
#define _DATAACCESS_DEPENDENT_DATA_H_
#include <vector>
#include "../BusinessObject/Dependent.h"

class DependentData{
private:
    vector<Dependent> _data;
    int _maxId;
public:
    DependentData();
    int GetMaxId();
    int PushBack(Dependent);
    Dependent Get(int i);
};

#endif