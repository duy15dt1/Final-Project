#include "Dept_locations.h"
Dept_locations::Dept_locations() {
}

Dept_locations::Dept_locations(int Dnumber, string Dlocation) {
    this->Dnumber = Dnumber;
    this->Dlocation = Dlocation;
}

void Dept_locations::IncreaseId() {
    Id = ++Idnew;
}

int& Dept_locations::GetId() {
    return Id;
}

int& Dept_locations::GetIdNew() {
    return Idnew;
}

string Dept_locations::ToString() {
    string s;
    s += "{Dnumber: " + to_string(Dnumber) + ", ";
    s += "Dlocation: " + Dlocation + "}";
    return s;
}

json Dept_locations::ToJson(){
    json j;
    j["Dnumber"] = Dnumber;
    j["Dlocation"] = Dlocation;
    return j;
}

int Dept_locations::Idnew = 0;
