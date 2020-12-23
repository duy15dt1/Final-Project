#include "Work_on.h"
//Default constructor
Work_on::Work_on() {
    Essn = 0;           //    Social security number of employee 
    Pno = 0;            //    Number of project 
    Hours = 0;          //    Overtime hours   
    Id = 0;             //    Identification of work_on sheet 
}; 

//Contructor with input parameters     
Work_on::Work_on(double Essn, int Pno, double Hours){
    this->Essn = Essn;          //    Social security number of employee 
    this->Pno = Pno;            //    Number of project 
    this->Hours = Hours;        //    Overtime hours 
};
//GetId() is a function that get ID value of overtime hour sheet 
int Work_on::GetId(){
    return Id;
}