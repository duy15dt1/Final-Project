#include "Employee.h"
// Default constructor
Employee::Employee() {
    Fname = Lname = Bdate = Address = " ";  // Assign variables Fname, Lname, Bdate, Address by ""
    Sex = Minit = ' '; 
    Bdate = Address = Sex = Salary = 0;
    Superssn = Dno = Ssn = 0;
}

// Constructor with input parameters
Employee::Employee(string Fname, char Minit, string Lname, double Ssn, 
string Bdate, string Address, char Sex, int Salary, double Superssn, int Dno) {
    this->Fname = Fname;
    this->Minit = Minit;
    this->Lname = Lname;
    this->Ssn = Ssn;
    this->Bdate = Bdate;
    this->Address = Address;
    this->Sex = Sex;
    this->Salary = Salary;
    this->Superssn = Superssn;
    this->Dno = Dno;
}