#include "Department.h"

Department::Department() {
}

//The this pointer is an implicit parameter to all member functions
//Therefore, inside a member function, this may be used to refer to the invoking object
Department::Department(string Dname, int Dnumber, int Mgrssn, string Mgrstartdate) {
    this->Dname = Dname;                 
    this->Dnumber = Dnumber;            
    this->Mgrssn = Mgrssn;               
    this->Mgrstartdate = Mgrstartdate; 
}
string Department::GetDName() {
    return Dname;
}
int Department::GetDNumber() {
    return Dnumber;
}
int Department::GetMgrssn() {
    return Mgrssn;
}
string Department::GetMgrstartdate() {
    return Mgrstartdate;
}
int& Department::GetIDMax() {
    return sIDMax;
}
void Department::IncreaseID() {
    ID = ++sIDMax;
}

/** Dnumber and Mgrssn are not string so we have to use "to_string"
 *  in library "string" to convert so that we can display
 *  DO NOT REMOVE "to_string" or it can get issues
 *  @return a string
 *  Example: 
 *  {Dname: Research, Dnumber: 5, Mgrssn: 333445555, Mgrstartdate: 1988-05-22}
 */

string Department::PrintElement() {
    string s;
    s += "Dname: " + Dname + ", ";
    s += "Dnumber:" + to_string(Dnumber) + ", ";
    s += "Mgrssn: " + to_string(Mgrssn) + ", ";
    s += "Mgrstartdate: " + Mgrstartdate + "";
    return s;
}

/** @brief Function converts this object to json object.
 *  
 *  Function converts this object to json object.
 *  @return a json object;
 *  Example: 
 *  {"Dname":"Research","Dnumber":5,"Mgrssn":333445555,"Mgrstartdate":"1988-05-22"}
 */
json Department::ToJson() {
    json j;
    j["Dname"] = Dname;
    j["Dnumber"] = Dnumber;
    j["Mgrssn"] = Mgrssn;
    j["Mgrstartdate"] = Mgrstartdate;
    return j;
}

//sIdMax is a static variable so we have to set it to 0 every time we want to use it
//to avoid unexpected issues
int Department::sIDMax = 0;             