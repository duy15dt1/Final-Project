#include "Dept_locations.h"
Dept_locations::Dept_locations() {}

Dept_locations::Dept_locations(int Dnumber, string Dlocation) {
    this->Dnumber = Dnumber;
    this->Dlocation = Dlocation;
}

int& Dept_locations::GetId() {
    return Id;
}

int& Dept_locations::GetIdNew() {
    return Idnew;
}

void Dept_locations::IncreaseId() {
    Id = ++Idnew;
}

/** Dnumber is not string so we have to use "to_string"
 *  in library "string" to convert so that we can display
 *  DO NOT REMOVE "to_string" or it can get issues
 *  @return a string
 *  Example: 
 *  {Dnumber: 1, Dlocation: Houston}
 */
string Dept_locations::ToString() {
    string s;
    s += "{Dnumber: " + to_string(Dnumber) + ", ";
    s += "Dlocation: " + Dlocation + "}";
    return s;
}

/** @brief Function converts this object to json object.
 *  
 *  Function converts this object to json object.
 *  @return a json object;
 *  Example: 
 *  {"Dnumber":1,"Dlocation":"Houston"}
 */
json Dept_locations::ToJson(){
    json j;
    j["Dnumber"] = Dnumber;
    j["Dlocation"] = Dlocation;
    return j;
}

int Dept_locations::Idnew = 0;