#include "Dependent.h"
//Default constructor
Dependent::Dependent() {
    Essn = 0;                    //Social security number of employee
    Dependent_name = "";          //Name of dependent
    Sex = ' ';                       //Sex of dependent
    Bdate = "";                   //Date of birth of employee
    Relationship = "";            //Relationship of dependent
};

//Constructor with input parameters
Dependent::Dependent(double Essn, string Dependent_name, char Sex, string Bdate, string Relationship){
    this->Essn = Essn;                    //Social security number of employee
    this->Dependent_name = Dependent_name;          //Name of dependent
    this->Sex = Sex;                       //Sex of dependent
    this->Bdate = Bdate;                   //Date of birth of employee
    this->Relationship = Relationship;            //Relationship of dependent
};