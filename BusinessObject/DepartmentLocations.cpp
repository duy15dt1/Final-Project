#include "DepartmentLocations.h"
DepartmentLocations::DepartmentLocations() {
}

DepartmentLocations::DepartmentLocations(int Dnumber, string Dlocation) {
    this->Dnumber = Dnumber;
    this->Dlocation = Dlocation;
}
int& DepartmentLocations::GetIDMax() {
    return sIDMax;
}
void DepartmentLocations::IncreaseID() {
    ID = ++sIDMax;
}

/** Dnumber is not string so we have to use "to_string"
 *  in library "string" to convert so that we can display
 *  DO NOT REMOVE "to_string" or it can get issues
 *  @return a string
 *  Example: 
 *  {Dnumber: 1, Dlocation: Houston}
 */
string DepartmentLocations::ToString() {
    string s;
    s += "{Dnumber: " + to_string(Dnumber) + ", ";
    s += "Dlocation: " + Dlocation + "}";
    return s;
}

string DepartmentLocations::PrintElement() {
    string s;
    s += "Dnumber: " + to_string(Dnumber) + ", ";
    s += "Dlocation: " + Dlocation + ", ";
    return s;
}

/** @brief Function converts this object to json object.
 *  
 *  Function converts this object to json object.
 *  @return a json object;
 *  Example: 
 *  {"Dnumber":1,"Dlocation":"Houston"}
 */
json DepartmentLocations::ToJson() {
    json j;
    j["Dnumber"] = Dnumber;
    j["Dlocation"] = Dlocation;
    return j;
}

int DepartmentLocations::sIDMax = 0;