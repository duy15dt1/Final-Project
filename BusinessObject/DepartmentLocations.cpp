#include "DepartmentLocations.h"
DepartmentLocations::DepartmentLocations() {
}

//The this pointer is an implicit parameter to all member functions
//Therefore, inside a member function, this may be used to refer to the invoking object
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

//sIdMax is a static variable so we have to set it to 0 every time we want to use it
//to avoid unexpected issues
int DepartmentLocations::sIDMax = 0;