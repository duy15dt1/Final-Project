//Class contains all information of object Dependent
#ifndef _BusinessObject_Dependent_H_
#define _BusinessObject_Dependent_H_
#include <string>

#include "BusinessObject.h"
#include "../libs/json.hpp" 

using namespace std;
using json = nlohmann::json;

class Dependent : public BusinessObject {
private:
    //Original member of the class
    int Essn;                       // Social security number of employee
    string DependentName;          // Name of dependent
    char Sex;                       // Sex of dependent
    string Bdate;                   // Date of birth of employee
    string Relationship;            // Relationship of dependent

    //Objects of the class has no serial number so we add the variable Id
    //to access the object whenever we want.
    //The IdNew exists because when we add or delete an object in the class
    //we will use this variable to identify the new serial number of the object
    static int sIDMax;               // Identification of Dependent sheet for update
public:
    Dependent();         
    Dependent(int, string, char, string, string);
    
    //All 2 methods below are private so we declare these functions 
    //to return the value of Relationship and Essn to use in another method
    int GetEssn();
    char GetSex();
    string GetBdate();
    string GetRelationship();
    //
    int& GetIDMax();
    void IncreaseID();

    //Convert the informations of Dependent to string type to display to screen
    string ToString();

    //Convert the informations of Dependent to json type to save file
    json ToJson();
    string PrintElement();
    friend istream& operator >> (istream& is, Dependent& dep);
};
#endif