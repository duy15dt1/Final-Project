#include "Dependent.h"
//Default constructor
Dependent::Dependent(){};

//Constructor with input parameters
Dependent::Dependent(int Essn, string Dependent_name, char Sex, string Bdate, string Relationship){
    this->Essn = Essn;                    //Social security number of employee
    this->Dependent_name = Dependent_name;          //Name of dependent
    this->Sex = Sex;                       //Sex of dependent
    this->Bdate = Bdate;                   //Date of birth of employee
    this->Relationship = Relationship;            //Relationship of dependent
    Id = ++IdNew;
};

int Dependent::GetId(){
    return Id;
}

string Dependent::ToString(){
    string s;
    s += "{";
    s += to_string(Essn) + ", ";
    s += Dependent_name + ", ";
    string str = string(1,Sex);
    s += str + ", ";
    s += Bdate + ", ";
    s += Relationship +"}";
    return s;
}
int Dependent::IdNew = 0;