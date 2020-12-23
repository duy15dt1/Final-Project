#include "Employee.h"
// Default constructor
Employee::Employee() {
    Fname = Lname = Bdate = Address = Minit = " ";  // Assign variables Fname, Lname, Bdate, Address by ""
    Sex = ' '; 
    Bdate = Address = Sex = Salary = 0;
    Superssn = Dno = Ssn = 0;

}

// Constructor with input parameters
Employee::Employee(string Fname, string Minit, string Lname, int Ssn, 
string Bdate, string Address, char Sex, int Salary, int Superssn, int Dno) {
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

Employee::Employee(const Employee& emp) {
    Fname = emp.Fname;   
    Minit = emp.Minit;
    Lname = emp.Lname;     
    Ssn = emp.Ssn;       
    Bdate = emp.Bdate;     
    Address = emp.Address;   
    Sex = emp.Sex;         
    Salary = emp.Salary;       
    Superssn = emp.Superssn;  
    Dno = emp.Dno;        
    Id = emp.Id;
}

int& Employee::GetId() {
    return Id;
}

string Employee::ToString() {
    string s;
    s += "{Fname: " + Fname + ", ";
    s += "MInit:" + Minit + ", ";
    s += "Lname: " + Lname + ", ";
    s += "SSN: " + to_string(Ssn) + ", ";
    s += "BDate: " + Bdate + ", ";
    s += "Adrress: " + Address + ", ";
    string str = string(1, Sex);
    s += "Sex: " + str + ", ";
    s += "Salary: " + to_string(Salary) + ", ";
    s += "SuperSSN: " + to_string(Superssn) + ", ";
    s += "DNO: " + to_string(Dno) + "}";
    return s;
}

void Employee::IncreaseId() {
    Id = ++Idnew;
}

int Employee::Idnew = 0;