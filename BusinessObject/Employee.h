#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <string>
#include "BusinessObject.h"
#include "../libs/json.hpp"
using namespace std;
using json = nlohmann::json;
class Employee : public BusinessObject {
private: 
    string Fname;     // First name of employee
    string Minit;       // Middle name of employe
    string Lname;     // Last name of employee
    int Ssn;       // Social security number of employee
    string Bdate;     // Birth day of employee
    string Address;   // Address of employee
    char Sex;         // Sex of employee
    int Salary;       // Salary of employee
    int Superssn;  // Superssn of employee
    int Dno;          // Dno of employee
    int Id;
    static int Idnew;
public:    
    // Default constructor
    Employee(); 
    // Constructor with input parameters
    Employee(string Fname, string Minit, string Lname, int Ssn, string Bdate, string Address, char Sex, int Salary, int Superssn, int Dno);   
    void IncreaseId();
    int& GetId();
    int& GetIdNew();
    string ToString();
    json ToJson();
    friend istream& operator >> (istream& is, Employee& emp);
};

#endif