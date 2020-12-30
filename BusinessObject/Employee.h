//Class contains all information of object Employee
#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <string>
#include "BusinessObject.h"
#include "../libs/json.hpp"
using namespace std;
using json = nlohmann::json;
class Employee : public BusinessObject {
private:
    //Original member of the class
    string Fname;       // First name of employee
    string Minit;       // Middle name of employe
    string Lname;       // Last name of employee
    int Ssn;            // Social security number of employee
    string Bdate;       // Birth day of employee
    string Address;     // Address of employee
    char Sex;           // Sex of employee
    int Salary;         // Salary of employee
    int Superssn;       // Superssn of employee
    int Dno;            // Dno of employee

    //Objects of the class has no serial number so we add the variable Id
    //to access the object whenever we want.
    //The IdNew exists because when we add or delete an object in the class
    //we will use this variable to identify the new serial number of the object
    int Id;             // The current identification of Employee sheet 
    static int Idnew;   // Identification of Employee sheet for update
public:    
    Employee(); 
    Employee(string Fname, string Minit, string Lname, int Ssn, string Bdate, string Address, char Sex, int Salary, int Superssn, int Dno);   
    
    //All 6 methods below are private so we declare these functions 
    //to return the value of Name, Superssn, Dno, Salary, Sex to use in another method
    string GetName();
    int GetSuperssn();
    int GetSsn();
    int GetDno();
    int GetSalary();
    char GetSex();    

    //
    int& GetId();
    int& GetIdNew();
    void IncreaseId();
    
    //Convert the informations of Employee to string type to display to screen
    string ToString();

    //Convert the informations of Employee to json type to save file
    json ToJson();

    friend istream& operator >> (istream& is, Employee& emp);
};

#endif