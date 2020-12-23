#include "DependentData.h"

DependentData::DependentData(){
    _maxId = 0;
    _data.resize(0);
}

int DependentData::GetMaxId(){
    return _maxId;
}

int DependentData::PushBack(Dependent d){
    if (_maxId < d.GetId()){
        _maxId = d.GetId();
    }
    _data.push_back(d);
    return _maxId;
}

Dependent DependentData::Get(int i){
    return _data[i];
}