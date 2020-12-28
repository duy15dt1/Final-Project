#include "Work_on.h"
//Default constructor
Work_on::Work_on() {  
}; 

//Contructor with input parameters     
Work_on::Work_on(int Essn, int Pno, double Hours){
    this->Essn = Essn;
    this->Pno = Pno;
    this->Hours = Hours;
}
//GetId() is a function that get ID value of overtime hour sheet 
int& Work_on::GetId(){
    return Id;
}
int& Work_on::GetIdNew(){
    return IdNew;
}
//ToString() is a function that convert the informations of work_on sheet to string type
string Work_on::ToString(){
    string s;
    s += "{ ";
    s += to_string(Essn) + ",";
    s += to_string(Pno) + ",";
    s += to_string(Hours) + "}";
    return s;   
}
//ToString() is a function that convert the informations of work_on sheet to json type to save file
json Work_on::ToJson(){
    json j;
    j["Essn"] = Essn;
    j["Pno"] = Pno;
    j["Hours"] = Hours;
    return j;
}
void Work_on::IncreaseId(){
    Id = ++IdNew;
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
int Work_on::IdNew = 0;