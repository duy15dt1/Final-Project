//Class contains all information of object Employee
#ifndef _BusinessObject_Employee_H_
#define _BusinessObject_Employee_H_
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
    static int sIDMax;   // Identification of Employee sheet for update
public:    
    Employee(); 
    Employee(string , string, string, int, string, string, char, int, int, int);   
    
    //All 6 methods below are private so we declare these functions 
    //to return the value of Name, Superssn, Dno, Salary, Sex to use in another method
    string GetName();
    string GetFname();
    string GetMinit();
    string GetLname();
    int GetSsn();
    string GetBdate();
    string GetAddress();
    char GetSex(); 
    int GetSalary();
    int GetSuperssn();
    int GetDno();

    int& GetIDMax();
    void IncreaseID();
    
    //Convert the informations of every member of Employee to string type to display to screen
    string ToString();

    //Convert the informations of Employee to json type to save file
    json ToJson();
    string PrintElement();
    friend istream& operator >> (istream&, Employee&);
};

#endif