//Class contains all information of object Department location
#ifndef _BusinessObject_DepartmentLocations_H_
#define _BusinessObject_DepartmentLocations_H_
#include <string>  

#include "BusinessObject.h"
#include "../libs/json.hpp"

using namespace std;
using json = nlohmann::json;

class DepartmentLocations : public BusinessObject {
private:
    //Original member of the class
    int Dnumber;          // Number of department
    string Dlocation;     // Location of department
    
    //Objects of the class has no serial number so we add the variable Id
    //to access the object whenever we want.
    //The IdNew exists because when we add or delete an object in the class
    //we will use this variable to identify the new serial number of the object
    static int sIDMax;     // Identification of Deparment location sheet for update 
public:
    DepartmentLocations();
    DepartmentLocations(int, string);
    //
    int& GetIDMax();
    void IncreaseID();
    //Convert the informations of every member of Deparment location to string type to display to screen
    json ToJson();
    //Convert the informations of Deparment location to json type to save file
    string PrintElement();
    //
    friend istream& operator >> (istream& , DepartmentLocations&);
};
#endif