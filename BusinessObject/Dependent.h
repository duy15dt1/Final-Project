//Class contains all information of object Dependent
#ifndef _DEPENDENT_H_
#define _DEPENDENT_H_
#include <string>
#include "BusinessObject.h"
#include "../libs/json.hpp" 
using namespace std;
using json = nlohmann::json;
class Dependent : public BusinessObject{
private:
    //Original member of the class
    int Essn;                       // Social security number of employee
    string Dependent_name;          // Name of dependent
    char Sex;                       // Sex of dependent
    string Bdate;                   // Date of birth of employee
    string Relationship;            // Relationship of dependent

    //Objects of the class has no serial number so we add the variable Id
    //to access the object whenever we want.
    //The IdNew exists because when we add or delete an object in the class
    //we will use this variable to identify the new serial number of the object
    int Id;                         // The current identification of Dependent sheet
    static int IdNew;               // Identification of Dependent sheet for update
public:
    Dependent();         
    Dependent(int Essn, string Dependent_name, char Sex, string Bdate, string Relationship);
    
    //All 2 methods below are private so we declare these functions 
    //to return the value of Relationship and Essn to use in another method
    string GetRelationship();
    int GetEssn();

    //
    int& GetId();
    int& GetIdNew();
    void IncreaseId();

    //Convert the informations of Dependent to string type to display to screen
    string ToString();

    //Convert the informations of Dependent to json type to save file
    json ToJson();

    friend istream& operator >> (istream& is, Dependent& dep);
};
#endif