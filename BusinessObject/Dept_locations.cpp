#include "Dept_locations.h"
Dept_locations::Dept_locations() {
    Dnumber = 0;
    Dlocation = "";
    Id = ++Idnew;
}

Dept_locations::Dept_locations(int Dnumber, string Dlocation) {
    this->Dnumber = Dnumber;
    this->Dlocation = Dlocation;
    Id = ++Idnew;
}

int Dept_locations::GetId() {
    return Id;
}

string Dept_locations::ToString() {
    string s;
    s += "{Dnumber: " + to_string(Dnumber) + ", ";
    s += "Dlocation: " + Dlocation + "}";
    return s;
}

int Dept_locations::Idnew = 0;
