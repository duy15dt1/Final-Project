#include "Work_on.h"
Work_on::Work_on() {}
   
Work_on::Work_on(int Essn, int Pno, double Hours){
    this->Essn = Essn;
    this->Pno = Pno;
    this->Hours = Hours;
}

int Work_on::GetPno() {
    return Pno;
}
int Work_on::GetEssn() {
    return Essn;
}

double Work_on::GetHours() {
    return Hours;
}

int& Work_on::GetId(){
    return Id;
}
int& Work_on::GetIdNew(){
    return IdNew;
}
void Work_on::IncreaseId(){
    Id = ++IdNew;
}

/** Essn, Pno and Hours are not string so we have to use "to_string"
 *  in library "string" to convert so that we can display
 *  DO NOT REMOVE "to_string" or it can get issues
 *  @return a string
 *  Example: 
 *  {Essn: 123456789, Pno: 1, Hours: 32.5}
 */
string Work_on::ToString(){
    string s;
    s += "{Essn: " + to_string(Essn) + ",";
    s += "Pno: " + to_string(Pno) + ",";
    s += "Hours: " + to_string(Hours) + "}";
    return s;   
}

/** @brief Function converts this object to json object.
 *  
 *  Function converts this object to json object.
 *  @return a json object;
 *  Example: 
 *  {"Essn":123456789,"Pno":1,"Hours":32.5}
 */
json Work_on::ToJson(){
    json j;
    j["Essn"] = Essn;
    j["Pno"] = Pno;
    j["Hours"] = Hours;
    return j;
}

int Work_on::IdNew = 0;