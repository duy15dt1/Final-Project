//Class contains all information of object Work on
#ifndef _BusinessObject_Workson_H_
#define _BusinessObject_Workson_H_
#include <string>

#include "BusinessObject.h"
#include "../libs/json.hpp"

using namespace std;
using json = nlohmann::json;

class Workson : public BusinessObject {
private:
    //Original member of the class
    int Essn;           // Social security number of employee 
    int Pno;            // Number of project 
    double Hours;       // Overtime hours

    //Objects of the class has no serial number so we add the variable Id
    //to access the object whenever we want.
    //The IdNew exists because when we add or delete an object in the class
    //we will use this variable to identify the new serial number of the object
    static int sIDMax;   // Identification of Work_on sheet for update   
public:
    Workson();     
    Workson(int, int, double); 

    //All 3 methods below are private so we declare these functions 
    //to return the value of Pno, Essn, Hours to use in another method
    int GetEssn();
    int GetPno();
    double GetHours();
    int& GetIDMax();
    void IncreaseID();
    
    //Convert the informations of every member of Work_on to string type to display to screen
    string ToString();
    string PrintElement();
    //Convert the informations of Work_on to json type to save file
    json ToJson();

    friend istream& operator >> (istream&, Workson&);
};
#endif 