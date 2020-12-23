#include "DepartmentData.h"
    // Department d1("Research",5,333445555,"1988-05-22");
    // Department d2("Administration",4,987654321,"1995-01-01");
    // Department d3("Headquaters",1,888665555,"1981-06-19");
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