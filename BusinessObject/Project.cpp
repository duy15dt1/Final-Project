#include "Project.h"
//Default constructor
Project::Project(){};

//Constructor with input parameters
Project::Project(string Pname, int Pnumber, string Plocation, int Dnum){
    this->Pname = Pname;    
    this->Pnumber = Pnumber;    
    this->Plocation = Plocation;  
    this->Dnum = Dnum;
    Id = ++IdNew;         
};

int Project::GetId(){
    return Id;
}

string Project::ToString(){
    string s;
    s += "{";
    s += Pname + ", ";
    s += to_string(Pnumber) + ", ";
    s += Plocation + ", ";
    s += to_string(Dnum) + "}";
    return s;
}
int Project::IdNew = 0;