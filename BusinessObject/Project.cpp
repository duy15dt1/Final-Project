#include "Project.h"
Project::Project(){
}

//The this pointer is an implicit parameter to all member functions
//Therefore, inside a member function, this may be used to refer to the invoking object
Project::Project(string Pname, int Pnumber, string Plocation, int Dnum){
    this->Pname = Pname;    
    this->Pnumber = Pnumber;    
    this->Plocation = Plocation;  
    this->Dnum = Dnum;       
}

int Project::GetPnumber() {
    return Pnumber;
}
string Project::GetPname() {
    return Pname;
}
int Project::GetDnum() {
    return Dnum;
}
int& Project::GetIDMax(){
    return sIDMax;
}

void Project::IncreaseID(){
    ID = ++sIDMax;
}

/** Pnumber and Dnum are not string so we have to use "to_string"
 *  in library "string" to convert so that we can display
 *  DO NOT REMOVE "to_string" or it can get issues
 *  @return a string
 *  Example: 
 *  {Pname: ProductX, Pnumber: 1, Plocation: Bellaire, Dnum: 5}
 */
string Project::PrintElement(){
    string s;
    s += "Pname: " + Pname + ", ";
    s += "Pnumber: " + to_string(Pnumber) + ", ";
    s += "Plocation: " + Plocation + ", ";
    s += "Dnumber: " + to_string(Dnum) + "";
    return s;
}

/** @brief Function converts this object to json object.
 *  
 *  Function converts this object to json object.
 *  @return a json object;
 *  Example: 
 *  {"Pname":"ProductX","Pnumber":1,"Plocation":"Bellaire","Dnum":5}
 */
json Project::ToJson(){
    json j;
    j["Pname"] = Pname;
    j["Pnumber"] = Pnumber;
    j["Plocation"] = Plocation;
    j["Dnum"] = Dnum;
    return j;
}

//sIdMax is a static variable so we have to set it to 0 every time we want to use it
//to avoid unexpected issues
int Project::sIDMax = 0;