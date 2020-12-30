#include "DepartmentData.h"
#include "iostream"
#include "fstream"
#include "../libs/json.hpp"
using namespace std;
using json = nlohmann::json;

DepartmentData::DepartmentData(){
    _maxId = 0;
    _departmentArr.resize(0);
}
//Read from file 
void DepartmentData::Read(string filename){
    if(_departmentArr.size() != 0 ){
        _departmentArr.back().GetIdNew() = 0;
    }
    _maxId = 0;
    _departmentArr.resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize];
    while(inFile.getline(buff,maxSize)) {
        json j = json::parse(buff);
        Department depa(
            j["Dname"],
            j["Dnumber"],
            j["Mgrssn"],
            j["Mgrstartdate"]
        );
        depa.IncreaseId();
        _departmentArr.push_back(depa);
    }
    inFile.close();
}

//GetMaxId() is a function that get the maximum ID of department data
int DepartmentData::GetMaxId(){
    return _maxId;
}
// PushBack(Department) is a function that push one department data in the back of _departmentArr vector and return maximun ID of the current _departmentArr vector

//Get(int i) is a function that get the department data at i position of _departmentArr vector
Department& DepartmentData::Get(int i){
    return _departmentArr[i];
}

BusinessObject* DepartmentData::GetPointer(int i) {
    return &_departmentArr[i];
}

void DepartmentData::Delete(int i){
    _departmentArr.erase(_departmentArr.begin()+i-1);
    _maxId = _departmentArr.size();
    for (int j = i-1; j < _maxId ; j++ ){
        _departmentArr[j].GetId() = j + 1; 
    } 
    _departmentArr.back().GetIdNew() = _maxId;
}

void DepartmentData::Add(Department& deparment){
    deparment.IncreaseId();
    _departmentArr.push_back(deparment);
}
void DepartmentData::Edit(int i){
    cin >> _departmentArr[i];
}
int DepartmentData::GetSize() {
    return _departmentArr.size();
}
int DepartmentData::ExportToFile(string filename){
    ofstream outFile(filename,ios::out);
    if(!outFile) return 0;
    for( Department depa:_departmentArr){
        outFile << depa.ToJson() << endl;
    }
    outFile.close();
    return 1;
}