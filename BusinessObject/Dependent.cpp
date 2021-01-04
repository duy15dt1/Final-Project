#include "Dependent.h"
Dependent::Dependent() {
}

//The this pointer is an implicit parameter to all member functions
//Therefore, inside a member function, this may be used to refer to the invoking object
Dependent::Dependent(int Essn, string DependentName, char Sex, string Bdate, string Relationship) {
    this->Essn = Essn;                    
    this->DependentName = DependentName;          
    this->Sex = Sex;                       
    this->Bdate = Bdate;                  
    this->Relationship = Relationship;          
}
int Dependent::GetEssn() {
    return Essn;
}
char Dependent::GetSex() {
    return Sex;
}
string Dependent::GetBdate() {
    return Bdate;
}
string Dependent::GetRelationship() {
    return Relationship;
}
int& Dependent::GetIDMax() {
    return sIDMax;
}

void Dependent::IncreaseID() {
    ID = ++sIDMax;
}

/** Essn is not string so we have to use "to_string"
 *  in library "string" to convert so that we can display
 *  DO NOT REMOVE "to_string" or it can get issues
 *  @return a string
 *  Example: 
 *  {Essn: 333445555, Dependent_name: Alice, Sex: F, Bdate: 1986-04-05, Relationship: DAUGHTER}
 */

string Dependent::PrintElement() {
    string s;
    s += "Essn: " + to_string(Essn) + ", ";
    s += "Dependent name: " + DependentName + ", ";
    //Sex is type char so we convert to string then get the first character
    string str = string(1,Sex); 
    s += "Sex: " + str + ", ";
    s += "Bdate: " + Bdate + ", ";
    s += "Relationship: " + Relationship;
    return s;
}

/** @brief Function converts this object to json object.
 *  
 *  Function converts this object to json object.
 *  @return a json object;
 *  Example: 
 *  {"Essn":333445555,"Dependent_name":"Alice","Sex":"F","Bdate":"1986-04-05","Relationship":"DAUGHTER"}
 */
json Dependent::ToJson() {
    json j;
    j["Essn"] = Essn;
    j["Dependent_name"] = DependentName;
    j["Sex"] = string(1, Sex);
    j["Bdate"] = Bdate;
    j["Relationship"] = Relationship;
    return j;
}

//sIdMax is a static variable so we have to set it to 0 every time we want to use it
//to avoid unexpected issues
int Dependent::sIDMax = 0;