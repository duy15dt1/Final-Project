#include "Department.h"
//Default constructor
Department::Department() {
}

//Contructor with input parameters     
Department::Department(string Dname, int Dnumber, int Mgrssn, string Mgrstartdate){
    this->Dname = Dname;                //    Name of department 
    this->Dnumber = Dnumber;            //    Number of department 
    this->Mgrssn = Mgrssn;              //    Social security number of manager 
    this->Mgrstartdate = Mgrstartdate;  //    Department management start date of manager 
}

//GetId() is a function that get ID value of department 
int& Department::GetId(){
    return Id;
}

int& Department::GetIdNew(){
    return IdNew;
}
//ToString() is a function that convert the informations of department to string type
string Department::ToString(){
    string s;
    s += "{ ";
    s += Dname + ",";
    s += to_string(Dnumber) + ",";
    s += to_string(Mgrssn) + ",";
    s += Mgrstartdate + "}";
    return s;
}
//ToString() is a function that convert the informations of department to json type to save file
json Department::ToJson(){
    json j;
    j["Dname"] = Dname;
    j["Dnumber"] = Dnumber;
    j["Mgrssn"] = Mgrssn;
    j["Mgrstartdate"] = Mgrstartdate;
    return j;
}
void Department::IncreaseId(){
    Id = ++IdNew;
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
int Department::IdNew = 0;             //     Identification of department for update