#include "Workson.h"
Workson::Workson() {
}

//The this pointer is an implicit parameter to all member functions
//Therefore, inside a member function, this may be used to refer to the invoking object   
Workson::Workson(int Essn, int Pno, double Hours){
    this->Essn = Essn;
    this->Pno = Pno;
    this->Hours = Hours;
}
int Workson::GetEssn() {
    return Essn;
}
int Workson::GetPno() {
    return Pno;
}
double Workson::GetHours() {
    return Hours;
}
int& Workson::GetIDMax() {
    return sIDMax;
}
void Workson::IncreaseID() {
    ID = ++sIDMax;
}

/** Essn, Pno and Hours are not string so we have to use "to_string"
 *  in library "string" to convert so that we can display
 *  DO NOT REMOVE "to_string" or it can get issues
 *  @return a string
 *  Example: 
 *  {Essn: 123456789, Pno: 1, Hours: 32.5}
 */

string Workson::PrintElement() {
    string s;
    s += "Essn: " + to_string(Essn) + ", ";
    s += "Pno: " + to_string(Pno) + ", ";
    s += "Hours: " + to_string(Hours) + "";
    return s;   
}

/** @brief Function converts this object to json object.
 *  
 *  Function converts this object to json object.
 *  @return a json object;
 *  Example: 
 *  {"Essn":123456789,"Pno":1,"Hours":32.5}
 */
json Workson::ToJson() {
    json j;
    j["Essn"] = Essn;
    j["Pno"] = Pno;
    j["Hours"] = Hours;
    return j;
}

//sIdMax is a static variable so we have to set it to 0 every time we want to use it
//to avoid unexpected issues
int Workson::sIDMax = 0;