#include "WorksonData.h"
#include <iostream>
#include <fstream>
#include "../libs/json.hpp"
using namespace std;
using json = nlohmann::json;
//Contructor function of WorksonData
WorksonData::WorksonData(){
    maxID = 0;
    worksonArr.resize(0);
}
//Read from file 
void WorksonData::Read(string filename) {
    if(worksonArr.size() != 0){
        worksonArr.back().GetIDMax() = 0;
    }
    maxID = 0;
    worksonArr.resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize];
    while(inFile.getline(buff,maxSize)) {
        json j = json::parse(buff);
        Workson work(
            j["Essn"],
            j["Pno"],
            j["Hours"]
        );
        work.IncreaseID();
        worksonArr.push_back(work);
    }
    inFile.close();
}
//GetMaxId() is a function that get the maximum ID of Workson data
int WorksonData:: GetMaxId() {
    return maxID;
}
// PushBack(Workson) is a function that push one Workson data in the back of worksonArr vector and return maximun ID of the current worksonArr vector
//Get(int i) is a function that get the Workson data at i position of worksonArr vector
Workson& WorksonData::Get(int i) {
    return worksonArr[i];
}
BusinessObject* WorksonData::GetPointer(int i) {
    return &worksonArr[i];
}
void WorksonData::Delete(int i){
    worksonArr.erase(worksonArr.begin()+i-1);
    maxID = worksonArr.size();
    for (int j = i-1; j < maxID ; j++ ){
        worksonArr[j].GetID() = j + 1; 
    } 
    worksonArr.back().GetIDMax() = maxID;
}

void WorksonData::Add(Workson& workson) {
    workson.IncreaseID();
    worksonArr.push_back(workson);
}
void WorksonData::Edit(Workson& workson,int i) {
    workson.GetID() = worksonArr[i].GetID();
    worksonArr[i] = workson;
}
int WorksonData::GetSize() {
    return worksonArr.size();
}
int WorksonData::ExportToFile(string filename) {
    ofstream outFile(filename,ios::out);
    if(!outFile) return 0;
    for (Workson work : worksonArr) {
        outFile << work.ToJson() << endl;
    }  
    outFile.close();
    return 1;
}