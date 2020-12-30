//Class contains all information of object Department location
#ifndef _DEPT_LOCATION_H_
#define _DEPT_LOCATION_H_
#include <string>   
#include "../libs/json.hpp"
#include "BusinessObject.h"
using namespace std;
using json = nlohmann::json;
class Dept_locations : public BusinessObject {
private:
    //Original member of the class
    int Dnumber;          // Number of department
    string Dlocation;     // Location of department
    
    //Objects of the class has no serial number so we add the variable Id
    //to access the object whenever we want.
    //The IdNew exists because when we add or delete an object in the class
    //we will use this variable to identify the new serial number of the object
    int Id;               // The current identification of Deparment location sheet
    static int Idnew;     // Identification of Deparment location sheet for update 
public:
    Dept_locations();
    Dept_locations(int Dnumber, string Dlocation);

    //
    int& GetId();
    int& GetIdNew();
    void IncreaseId();

    //Convert the informations of Deparment location to string type to display to screen
    json ToJson();

    //Convert the informations of Deparment location to json type to save file
    string ToString();

    //
    friend istream& operator >> (istream& , Dept_locations& );
};
#endif