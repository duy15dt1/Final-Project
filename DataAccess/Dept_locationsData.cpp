#include "Dept_locationsData.h"

using json = nlohmann::json;
Dept_locationsData::Dept_locationsData() {
    _deptlocationArr.resize(0);
    _maxId = 0;
}
int Dept_locationsData::GetMaxId() {
    return _maxId;
}

Dept_locations& Dept_locationsData::Get(int i) {
    return _deptlocationArr[i];
}
int Dept_locationsData::GetSize() {
    return _deptlocationArr.size();
}

void Dept_locationsData::Read(string filename){
    if (_deptlocationArr.size() != 0) {
        _deptlocationArr.back().GetIdNew() = 0;
    }
    _maxId = 0;
    _deptlocationArr.resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize]; 
    while (inFile.getline(buff,maxSize)) {
        json j = json::parse(buff);
        Dept_locations dept(
            j["Dnumber"],
            j["Dlocation"]
        );
        dept.IncreaseId();
        _deptlocationArr.push_back(dept);
    }
    inFile.close();
}

void Dept_locationsData::Delete(int i) {
    _deptlocationArr.erase(_deptlocationArr.begin() + i - 1);
    _maxId = _deptlocationArr.size();
    for (int j = i-1; j < _maxId; j++){
        _deptlocationArr[j].GetId() = j + 1;
    }
    _deptlocationArr.back().GetIdNew() = _maxId;
}

void Dept_locationsData::Add() {
    Dept_locations dept;
    cin >> dept;
    dept.IncreaseId();
    _deptlocationArr.push_back(dept);
}

void Dept_locationsData::Edit(int i) {
    cin >> _deptlocationArr[i];
}

int Dept_locationsData::ExportToFile(string filename){
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Dept_locations dept :_deptlocationArr){
        outFile << dept.ToJson() << endl;
    }
    outFile.close();
    return 1;
}