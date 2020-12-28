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
};

int& Dependent::GetId(){
    return Id;
}

int& Dependent::GetIdNew(){
    return IdNew;
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

json Dependent::ToJson(){
    json j;
    j["Essn"] = Essn;
    j["Dependent_name"] = Dependent_name;
    j["Sex"] = string(1, Sex);
    j["Bdate"] = Bdate;
    j["Relationship"] = Relationship;
    return j;
}

void Dependent::IncreaseId(){
    Id = ++ IdNew;
}

string Dependent::GetRelationship() {
    return Relationship;
}

int Dependent::GetEssn() {
    return Essn;
}

int Dependent::IdNew = 0;