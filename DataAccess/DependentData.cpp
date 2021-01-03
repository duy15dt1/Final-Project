#include "DependentData.h"

DependentData::DependentData() {
    maxId = 0;
    dependentArr.resize(0);
}

int DependentData::GetMaxId() {
    return maxId;
}

int DependentData::GetSize(){
    return dependentArr.size();
}

//The Get(int i) function will get the data at position i of vector dependentArr
//and the GetPointer() function will get the address of that position
Dependent& DependentData::Get(int i){
    return  dependentArr[i];
}

BusinessObject* DependentData::GetPointer(int i) {
    return &dependentArr[i];
}

//We increae the id in order to point to the new member
//then using push_back() function to store it at the last of the vector
void DependentData::Add(Dependent& dependent) {
    dependent.IncreaseID();
    dependentArr.push_back(dependent);
}

//After locating the position of the member we want to edit
//Overwrite them by the new member
void DependentData::Edit(Dependent& dependent,int i) {
    dependentArr[i] = dependent;
}

void DependentData::Delete(int i) {
    dependentArr.erase(dependentArr.begin() + i - 1);
    maxId = dependentArr.size();
    for (int j = i-1; j < maxId; j++){
        dependentArr[j].GetID() = j + 1;
    }
    dependentArr.back().GetIDMax() = maxId;
}

void DependentData::Read(string filename) {
    if (dependentArr.size() != 0) {
        dependentArr.back().GetIDMax() = 0;
    }
    maxId = 0;
    dependentArr.resize(0);
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
        d.IncreaseID();
        dependentArr.push_back(d);
    }
    inFile.close();
}

int DependentData::ExportToFile(string filename) {
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Dependent d :dependentArr){
        outFile << d.ToJson() <<endl;
    }
    outFile.close();
    return 1;
}