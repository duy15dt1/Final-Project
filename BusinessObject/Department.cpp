#include "Department.h"
//Default constructor
Department::Department() {
    Dname = "";         //    Name of department 
    Dnumber = 0;        //    Number of department 
    Mgrssn = 0;         //    Social security number of manager 
    Mgrstartdate = "";  //    Department management start date of manager 
}; 

//Contructor with input parameters     
Department::Department(string Dname, int Dnumber, double Mgrssn, string Mgrstartdate){
    this->Dname = Dname;                //    Name of department 
    this->Dnumber = Dnumber;            //    Number of department 
    this->Mgrssn = Mgrssn;              //    Social security number of manager 
    this->Mgrstartdate = Mgrstartdate;  //    Department management start date of manager 
};