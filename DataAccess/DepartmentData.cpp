#include "DepartmentData.h"
DepartmentData::DepartmentData() {
    maxID = 0;
    departmentArr.resize(0);
}

int DepartmentData::GetMaxID() {
    return maxID;
}
//The Get(int i) function will get the data at position i of vector departmentArr
//and the GetPointer() function will get the address of that position
Department& DepartmentData::Get(int i) {
    return departmentArr[i];
}

BusinessObject* DepartmentData::GetPointer(int i) {
    return &departmentArr[i];
}

int DepartmentData::GetSize() {
    return departmentArr.size();
}

//We increae the id in order to point to the new member
//then using push_back() function to store it at the last of the vector
void DepartmentData::Add(Department& deparment) {
    deparment.IncreaseID();
    departmentArr.push_back(deparment);
}

//After locating the position of the member we want to edit
//Overwrite them by the new member
void DepartmentData::Edit(Department& deparment,int i) {
    deparment.GetID() = departmentArr[i].GetID();
    departmentArr[i] = deparment;
}

void DepartmentData::Delete(int i) {
    departmentArr.erase(departmentArr.begin()+i-1);
    maxID = departmentArr.size();
    for (int j = i-1; j < maxID ; j++ ){
        departmentArr[j].GetID() = j + 1; 
    } 
    departmentArr.back().GetIDMax() = maxID;
}

void DepartmentData::Read(string filename) {
    if(departmentArr.size() != 0 ){
        departmentArr.back().GetIDMax() = 0;
    }
    maxID = 0;
    departmentArr.resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize];
    while(inFile.getline(buff,maxSize)) {
        json j = json::parse(buff);
        Department department(
            j["Dname"],
            j["Dnumber"],
            j["Mgrssn"],
            j["Mgrstartdate"]
        );
        department.IncreaseID();
        departmentArr.push_back(department);
    }
    inFile.close();
}

int DepartmentData::ExportToFile(string filename) {
    ofstream outFile(filename,ios::out);
    if(!outFile) return 0;
    for( Department department:departmentArr) {
        outFile << department.ToJson() << endl;
    }
    outFile.close();
    return 1;
}