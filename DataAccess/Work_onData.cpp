#include "Work_onData.h"
#include <iostream>
#include <fstream>
#include "../libs/json.hpp"
using namespace std;
using json = nlohmann::json;
//Contructor function of Work_onData
Work_onData::Work_onData(){
    _maxId = 0;
    _workonArr.resize(0);
}
//Read from file 
void Work_onData::Read(string filename){
    if(_workonArr.size() != 0){
        _workonArr.back().GetIdNew() = 0;
    }
    _maxId = 0;
    _workonArr.resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize];
    while(inFile.getline(buff,maxSize)){
        json j = json::parse(buff);
        Work_on work(
            j["Essn"],
            j["Pno"],
            j["Hours"]
        );
        work.IncreaseId();
        _workonArr.push_back(work);
    }
    inFile.close();
}
//GetMaxId() is a function that get the maximum ID of Work_on data
int Work_onData:: GetMaxId(){
    return _maxId;
}
// PushBack(Work_on) is a function that push one Work_on data in the back of _workonArr vector and return maximun ID of the current _workonArr vector
//Get(int i) is a function that get the Work_on data at i position of _workonArr vector
Work_on& Work_onData::Get(int i){
    return _workonArr[i];
}
BusinessObject* Work_onData::GetPointer(int i) {
    return &_workonArr[i];
}
void Work_onData::Delete(int i){
    _workonArr.erase(_workonArr.begin()+i-1);
    _maxId = _workonArr.size();
    for (int j = i-1; j < _maxId ; j++ ){
        _workonArr[j].GetId() = j + 1; 
    } 
    _workonArr.back().GetIdNew() = _maxId;
}

void Work_onData::Add(Work_on& work_on){
    work_on.IncreaseId();
    _workonArr.push_back(work_on);
}
void Work_onData::Edit(Work_on& work_on,int i){
    work_on.GetId() = _workonArr[i].GetId();
    _workonArr[i] = work_on;
}
int Work_onData::GetSize() {
    return _workonArr.size();
}
int Work_onData::ExportToFile(string filename){
    ofstream outFile(filename,ios::out);
    if(!outFile) return 0;
    for (Work_on work : _workonArr){
        outFile << work.ToJson() << endl;
    }  
    outFile.close();
    return 1;
}