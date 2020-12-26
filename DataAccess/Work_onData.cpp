#include "Work_onData.h"
#include <iostream>
#include <fstream>
#include "../libs/json.hpp"
using namespace std;
using json = nlohmann::json;
//     Work_onData workondata;
//     Work_on w1(123456789,1,32.5);
//     Work_on w2(123456789,2,7.5);
//     Work_on w3(666884444,3,40.0);
//     Work_on w4(453453453,1,20.0);
//     Work_on w5(453453453,2,20.0);
//     Work_on w6(333445555,2,10.0);
//     Work_on w7(333445555,3,10.0);
//     Work_on w8(333445555,10,10.0);
//     Work_on w9(333445555,20,10.0);
//     Work_on w10(999887777,30,30.0);
//     Work_on w11(999887777,10,10.0);
//     Work_on w12(987987987,10,35.0);
//     Work_on w13(987987987,30,5.0);
//     Work_on w14(987654321,30,20.0);
//     Work_on w15(987654321,20,15.0);
//     Work_on w16(987987987,20,-1);
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
int Work_onData::PushBack(Work_on w){
    if (_maxId < w.GetId()){
        _maxId = w.GetId();
    }
    _workonArr.push_back(w);
    return _maxId;
}
//Get(int i) is a function that get the Work_on data at i position of _workonArr vector
Work_on& Work_onData::Get(int i){
    return _workonArr[i];
}
void Work_onData::Delete(int i){
    _workonArr.erase(_workonArr.begin()+i-1);
    _maxId = _workonArr.size();
    for (int j = i-1; j < _maxId ; j++ ){
        _workonArr[j].GetId() = j + 1; 
    } 
    _workonArr.back().GetIdNew() = _maxId;
}

void Work_onData::Add(){
    Work_on depa;
    cin >> depa;
    depa.IncreaseId();
    _workonArr.push_back(depa);
}
void Work_onData::Edit(int i){
    cin >> _workonArr[i];
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