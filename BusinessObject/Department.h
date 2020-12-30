//Class contains all information of object Deparment
#ifndef _DEPARTMENT_H_
#define _DEPARTMENT_H_
#include <string>
#include "BusinessObject.h"
#include "../libs/json.hpp"
using namespace std;
using json = nlohmann::json;
class Department : public BusinessObject {
private:
    //Original member of the class
    string Dname;       // Name of department 
    int Dnumber;        // Number of department 
    int Mgrssn;         // Social security number of manager 
    string Mgrstartdate;// Department management start date of manager

    //Objects of the class has no serial number so we add the variable Id
    //to access the object whenever we want.
    //The IdNew exists because when we add or delete an object in the class
    //we will use this variable to identify the new serial number of the object
    int Id;             // The current identification of Department sheet
    static int IdNew;   // Identification of Department sheet for update  
public:
    Department();      
    Department(string Dname, int Dnumber, int Mgrssn, string Mgrstartdate); 

    //All 3 methods below are private so we declare these functions 
    //to return the value of Dname, Dnumber, Mgrssn to use in another method
    string GetDepartmentName();
    int GetDepartmentNumber();
    int GetMgrssn();

    //
    int& GetId();
    int& GetIdNew();
    void IncreaseId();

    //Convert the informations of Department to string type to display to screen
    string ToString();

    //Convert the informations of Department to json type to save file
    json ToJson();

    friend istream& operator >> (istream& is, Department& depa);
};
#endif 