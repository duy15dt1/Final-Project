#include "DependentData.h"
#include <iostream>
#include <fstream>
#include "../libs/json.hpp"
using namespace std;
using json = nlohmann::json;

DependentData::DependentData(){
    _maxId = 0;
    _dependentArr.resize(0);
}

void DependentData::Read(string filename){
    if (_dependentArr.size() != 0) {
        _dependentArr.back().GetIdNew() = 0;
    }
    _maxId = 0;
    _dependentArr.resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize];
    while (inFile.getline(buff,maxSize)) {
        json j = json::parse(buff);
        string sex = j["Sex"];
        Dependent d(
            j["Essn"],
            j["Dependent_name"],
            sex[0],
            j["Bdate"],
            j["Relationship"]
        );
        d.IncreaseId();
        _dependentArr.push_back(d);
    }
    inFile.close();
}

int DependentData::GetMaxId(){
    return _maxId;
}


Dependent& DependentData::Get(int i){
    return  _dependentArr[i];
}

void DependentData::Delete(int i) {
    _dependentArr.erase(_dependentArr.begin() + i - 1);
    _maxId = _dependentArr.size();
    for (int j = i-1; j < _maxId; j++){
        _dependentArr[j].GetId() = j + 1;
    }
    _dependentArr.back().GetIdNew() = _maxId;
}

void DependentData::Add() {
    Dependent d;
    cin >> d;
    d.IncreaseId();
    _dependentArr.push_back(d);
}

void DependentData::Edit(int i) {
    cin >> _dependentArr[i];
}

int DependentData::GetSize(){
    return _dependentArr.size();
}

int DependentData::ExportToFile(string filename){
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Dependent d :_dependentArr){
        outFile << d.ToJson() <<endl;
    }
    outFile.close();
    return 1;
}