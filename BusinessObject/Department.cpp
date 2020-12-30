#include "Department.h"
Department::Department() {}
   
Department::Department(string Dname, int Dnumber, int Mgrssn, string Mgrstartdate){
    this->Dname = Dname;                 
    this->Dnumber = Dnumber;            
    this->Mgrssn = Mgrssn;               
    this->Mgrstartdate = Mgrstartdate; 
}

string Department::GetDepartmentName() {
    return Dname;
}

int Department::GetDepartmentNumber() {
    return Dnumber;
}
int Department::GetMgrssn() {
    return Mgrssn;
}

int& Department::GetId(){
    return Id;
}

int& Department::GetIdNew(){
    return IdNew;
}

void Department::IncreaseId(){
    Id = ++IdNew;
}

/** Dnumber and Mgrssn are not string so we have to use "to_string"
 *  in library "string" to convert so that we can display
 *  DO NOT REMOVE "to_string" or it can get issues
 *  @return a string
 *  Example: 
 *  {Dname: Research, Dnumber: 5, Mgrssn: 333445555, Mgrstartdate: 1988-05-22}
 */
string Department::ToString(){
    string s;
    s += "{Dname: " + Dname + ",";
    s += "Dnumber:" + to_string(Dnumber) + ",";
    s += "Mgrssn: " + to_string(Mgrssn) + ",";
    s += "Mgrstartdate" + Mgrstartdate + "}";
    return s;
}

/** @brief Function converts this object to json object.
 *  
 *  Function converts this object to json object.
 *  @return a json object;
 *  Example: 
 *  {"Dname":"Research","Dnumber":5,"Mgrssn":333445555,"Mgrstartdate":"1988-05-22"}
 */
json Department::ToJson(){
    json j;
    j["Dname"] = Dname;
    j["Dnumber"] = Dnumber;
    j["Mgrssn"] = Mgrssn;
    j["Mgrstartdate"] = Mgrstartdate;
    return j;
}

//
int Department::IdNew = 0;             