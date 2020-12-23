#ifndef DEPENDENTDATA_H_
#define DEPENDENTDATA_H_
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