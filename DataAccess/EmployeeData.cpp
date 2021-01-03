#include "EmployeeData.h"
#include <iostream>
#include <fstream>
#include "../libs/json.hpp"
using namespace std;

using json = nlohmann::json;

EmployeeData::EmployeeData(){
    maxID = 0;
    employeeArr.resize(0);
}

int EmployeeData::GetSize() {
    return employeeArr.size();
}

//The Get(int i) function will get the data at position i of vector employeeArr
//and the GetPointer() function will get the address of that position
Employee& EmployeeData::Get(int i) {
    return employeeArr[i];
}

BusinessObject* EmployeeData::GetPointer(int i) {
    return &employeeArr[i];
}

//We increae the id in order to point to the new member
//then using push_back() function to store it at the last of the vector
void EmployeeData::Add(Employee& employee) {
    employee.IncreaseID();
    employeeArr.push_back(employee);
}

//After locating the position of the member we want to edit
//Overwrite them by the new member
void EmployeeData::Edit(Employee& employee,int i){
    employee.GetID() = employeeArr[i].GetID();
    employeeArr[i] = employee;
}


void EmployeeData::Delete(int i) {
    employeeArr.erase(employeeArr.begin() + i - 1);
    maxID = employeeArr.size();
    for (int j = i-1; j < maxID; j++){
        employeeArr[j].GetID() = j + 1;
    }
    employeeArr.back().GetIDMax() = maxID;
}

void EmployeeData::Read(string filename){
    if (employeeArr.size() != 0) {
        employeeArr.back().GetIDMax() = 0;
    }
    maxID = 0;
    employeeArr.resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize]; 
    while (inFile.getline(buff,maxSize)) {
        json j = json::parse(buff);
        string sex = j["Sex"];
        Employee employee(
            j["Fname"],
            j["Minit"],
            j["Lname"],
            j["Ssn"],
            j["Bdate"],
            j["Address"],
            sex[0],
            j["Salary"],
            j["Superssn"],
            j["Dno"]
        );
        employee.IncreaseID();
        employeeArr.push_back(employee);
    }
    inFile.close();
}

int EmployeeData::ExportToFile(string filename){
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Employee e :employeeArr){
        outFile << e.ToJson() << endl;
    }
    outFile.close();
    return 1;
}

