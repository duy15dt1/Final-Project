#include "WorksonData.h"
#include <iostream>
#include <fstream>
#include "../libs/json.hpp"
using namespace std;
using json = nlohmann::json;

WorksonData::WorksonData(){
    maxID = 0;
    worksonArr.resize(0);
}

int WorksonData:: GetMaxId() {
    return maxID;
}

int WorksonData::GetSize() {
    return worksonArr.size();
}

//The Get(int i) function will get the data at position i of vector worksonArr
//and the GetPointer() function will get the address of that position
Workson& WorksonData::Get(int i) {
    return worksonArr[i];
}
BusinessObject* WorksonData::GetPointer(int i) {
    return &worksonArr[i];
}

//We increae the id in order to point to the new member
//then using push_back() function to store it at the last of the vector
void WorksonData::Add(Workson& workson) {
    workson.IncreaseID();
    worksonArr.push_back(workson);
}

//After locating the position of the member we want to edit
//Overwrite them by the new member
void WorksonData::Edit(Workson& workson,int i) {
    workson.GetID() = worksonArr[i].GetID();
    worksonArr[i] = workson;
}

void WorksonData::Delete(int i){
    worksonArr.erase(worksonArr.begin()+i-1);
    maxID = worksonArr.size();
    for (int j = i-1; j < maxID ; j++ ){
        worksonArr[j].GetID() = j + 1; 
    } 
    worksonArr.back().GetIDMax() = maxID;
}

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

int WorksonData::ExportToFile(string filename) {
    ofstream outFile(filename,ios::out);
    if(!outFile) return 0;
    for (Workson work : worksonArr) {
        outFile << work.ToJson() << endl;
    }  
    outFile.close();
    return 1;
}