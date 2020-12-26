#include "Project.h"
//Default constructor
Project::Project(){};

//Constructor with input parameters
Project::Project(string Pname, int Pnumber, string Plocation, int Dnum){
    this->Pname = Pname;    
    this->Pnumber = Pnumber;    
    this->Plocation = Plocation;  
    this->Dnum = Dnum;       
};

int& Project::GetId(){
    return Id;
}

int& Project::GetIdNew(){
    return IdNew;
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

json Project::ToJson(){
    json j;
    j["Pname"] = Pname;
    j["Pnumber"] = Pnumber;
    j["Plocation"] = Plocation;
    j["Dnum"] = Dnum;
    return j;
}

void Project::IncreaseId(){
    Id = ++ IdNew;
}

int Project::IdNew = 0;