#include "DepartmentData.h"
DepartmentData::DepartmentData() {
    maxID = 0;
    departmentArr.resize(0);
}
//Read from file 
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

//GetmaxID() is a function that get the maximum ID of department data
int DepartmentData::GetMaxID() {
    return maxID;
}
// PushBack(Department) is a function that push one department data in the back of _departmentArr vector and return maximun ID of the current _departmentArr vector

//Get(int i) is a function that get the department data at i position of _departmentArr vector
Department& DepartmentData::Get(int i) {
    return departmentArr[i];
}

BusinessObject* DepartmentData::GetPointer(int i) {
    return &departmentArr[i];
}

void DepartmentData::Delete(int i) {
    departmentArr.erase(departmentArr.begin()+i-1);
    maxID = departmentArr.size();
    for (int j = i-1; j < maxID ; j++ ){
        departmentArr[j].GetID() = j + 1; 
    } 
    departmentArr.back().GetIDMax() = maxID;
}

void DepartmentData::Add(Department& deparment) {
    deparment.IncreaseID();
    departmentArr.push_back(deparment);
}
void DepartmentData::Edit(Department& deparment,int i) {
    deparment.GetID() = departmentArr[i].GetID();
    departmentArr[i] = deparment;
}
int DepartmentData::GetSize() {
    return departmentArr.size();
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