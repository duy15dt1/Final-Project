#include "Department.h"
//Default constructor
Department::Department() {
    Dname = "";         //    Name of department 
    Dnumber = 0;        //    Number of department 
    Mgrssn = 0;         //    Social security number of manager 
    Mgrstartdate = "";  //    Department management start date of manager 
}

//Contructor with input parameters     
Department::Department(string Dname, int Dnumber, int Mgrssn, string Mgrstartdate){
    this->Dname = Dname;                //    Name of department 
    this->Dnumber = Dnumber;            //    Number of department 
    this->Mgrssn = Mgrssn;              //    Social security number of manager 
    this->Mgrstartdate = Mgrstartdate;  //    Department management start date of manager 
    Id = ++IdNew;
}
//GetId() is a function that get ID value of department 
int Department::GetId(){
    return Id;
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
int Department::IdNew = 0;             //     Identification of department for update