#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <string>
using namespace std;
class Employee {
private: 
    string Fname;     // First name of employee
    char Minit;       // Middle name of employe
    string Lname;     // Last name of employee
    double Ssn;       // Social security number of employee
    string Bdate;     // Birth day of employee
    string Address;   // Address of employee
    char Sex;         // Sex of employee
    int Salary;       // Salary of employee
    double Superssn;  // Superssn of employee
    int Dno;          // Dno of employee
    int Id;           // Id of employee
public:
    // Default constructor
    Employee(); 
          
    // Constructor with input parameters
    Employee(string Fname, char Minit, string Lname, double Ssn, 
    string Bdate, string Address, char Sex, int Salary, double Superssn, int Dno);   
    friend istream& operator >> (istream& is, Employee& emp);
    friend ostream& operator << (ostream& os, Employee& emp);
};

#endif