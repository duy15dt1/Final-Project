//Class contains all information of object Deparment
#ifndef _BusinessObject_Department_H_
#define _BusinessObject_Department_H_
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
    //The IDMax exists because when we add or delete an object in the class
    //we will use this variable to identify the new serial number of the object
    static int sIDMax;   // Identification of Department sheet for update  
public:
    Department();      
    Department(string, int, int, string); 

    //All 3 methods below are private so we declare these functions 
    //to return the value of Dname, Dnumber, Mgrssn to use in another method
    string GetDName();
    int GetDNumber();
    int GetMgrssn();
    string GetMgrstartdate();
    int& GetIDMax();
    void IncreaseID();

    //Convert the informations of every member of Department to string type to display to screen
    string ToString();

    //Convert the informations of Department to json type to save file
    json ToJson();
    string PrintElement();
    friend istream& operator >> (istream&, Department&);
};
#endif 