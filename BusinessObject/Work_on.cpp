#include "Work_on.h"
//Default constructor
Work_on::Work_on() {
    Essn = 0;           //    Social security number of employee 
    Pno = 0;            //    Number of project 
    Hours = 0;          //    Overtime hours   
}; 

//Contructor with input parameters     
Work_on::Work_on(double Essn, int Pno, double Hours){
    this->Essn = Essn;          //    Social security number of employee 
    this->Pno = Pno;            //    Number of project 
    this->Hours = Hours;        //    Overtime hours 
    Id = ++IdNew;
};
//GetId() is a function that get ID value of overtime hour sheet 
int Work_on::GetId(){
    return Id;
}
string Work_on::ToString(){
    string s;
    s += "{ ";
    s += to_string(Essn) + ",";
    s += to_string(Pno) + ",";
    s += to_string(Hours) + "}";
    return s;   
}
int Work_on::IdNew = 0;