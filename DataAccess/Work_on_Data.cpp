#include "DepartmentData.h"

//Contructor function of DepartmentData
DepartmentData::DepartmentData(){
    _maxId = 0;
    _data.resize(0);
}
//GetMaxId() is a function that get the maximum ID of department data
int DepartmentData:: GetMaxId(){
    return _maxId;
}
// PushBack(Department) is a function that push one department data in the back of _data vector and return maximun ID of the current _data vector
int DepartmentData:: PushBack(Department d){
    if (_maxId < d.GetId()){
        _maxId = d.GetId();
    }
    _data.push_back(d);
    return _maxId;
}
//Get(int i) is a function that get the department data at i position of _data vector
Department DepartmentData:: Get(int i){
    return _data[i];
}