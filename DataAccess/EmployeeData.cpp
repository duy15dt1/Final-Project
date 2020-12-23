#include "EmployeeData.h"
#include <iostream>
using namespace std;
EmployeeData::EmployeeData(){
    _maxId = 0;
    _employeeArr.resize(0);
}
int EmployeeData::GetMaxId(){
    return _maxId;
}
int EmployeeData::PushBack(Employee e){
    e.IncreaseId();
    if (_maxId < e.GetId()){
        _maxId = e.GetId();
    }
    _employeeArr.push_back(e);
    return _maxId;
}


Employee& EmployeeData::Get(int i) {
    return _employeeArr[i];
}

void EmployeeData::Erase(int i) {
    _employeeArr.erase(_employeeArr.begin() + i);
}


int EmployeeData::GetSize() {
    return _employeeArr.size();
}