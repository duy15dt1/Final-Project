#include "Dependent.h"
Dependent::Dependent(){};

Dependent::Dependent(int Essn, string Dependent_name, char Sex, string Bdate, string Relationship){
    this->Essn = Essn;                    
    this->Dependent_name = Dependent_name;          
    this->Sex = Sex;                       
    this->Bdate = Bdate;                  
    this->Relationship = Relationship;          
}

string Dependent::GetRelationship() {
    return Relationship;
}

int Dependent::GetEssn() {
    return Essn;
}

int& Dependent::GetId(){
    return Id;
}

int& Dependent::GetIdNew(){
    return IdNew;
}

void Dependent::IncreaseId(){
    Id = ++ IdNew;
}

/** Essn is not string so we have to use "to_string"
 *  in library "string" to convert so that we can display
 *  DO NOT REMOVE "to_string" or it can get issues
 *  @return a string
 *  Example: 
 *  {Essn: 333445555, Dependent_name: Alice, Sex: F, Bdate: 1986-04-05, Relationship: DAUGHTER}
 */
string Dependent::ToString(){
    string s;
    s += "{Essn: " + to_string(Essn) + ", ";
    s += "Dependent name: " + Dependent_name + ", ";
    //Sex is type char so we convert to string then get the first character
    string str = string(1,Sex); 
    s += "Sex: " + str + ", ";
    s += "Bdate: " + Bdate + ", ";
    s += "Relationship: " + Relationship +"}";
    return s;
}

/** @brief Function converts this object to json object.
 *  
 *  Function converts this object to json object.
 *  @return a json object;
 *  Example: 
 *  {"Essn":333445555,"Dependent_name":"Alice","Sex":"F","Bdate":"1986-04-05","Relationship":"DAUGHTER"}
 */
json Dependent::ToJson(){
    json j;
    j["Essn"] = Essn;
    j["Dependent_name"] = Dependent_name;
    j["Sex"] = string(1, Sex);
    j["Bdate"] = Bdate;
    j["Relationship"] = Relationship;
    return j;
}

//
int Dependent::IdNew = 0;