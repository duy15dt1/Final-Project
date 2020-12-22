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
};