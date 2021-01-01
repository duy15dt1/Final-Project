//create a class to contain information about project
#ifndef _BusinessObject_Project_H_
#define _BusinessObject_Project_H_
#include <string>  

#include "BusinessObject.h"
#include "../libs/json.hpp"

using namespace std;
using json = nlohmann::json;  

class Project : public BusinessObject{
private:
    //Original member of the class
    string Pname;      //Name of project
    int Pnumber;       //Serial number of project
    string Plocation;  //Location of project
    int Dnum;          //Number of department

    //Objects of the class has no serial number so we add the variable Id
    //to access the object whenever we want.
    //The IdNew exists because when we add or delete an object in the class
    //we will use this variable to identify the new serial number of the object
    static int sIDMax;   // Identification of Project sheet for update        
public:
    Project();         
    Project(string, int, string, int); 
    
    //All 3 methods below are private so we declare these functions 
    //to return the value of Pnumber, Pname, Dnum to use in another method
    string GetPname();
    int GetPnumber();
    string GetPlocation();
    int GetDnum();
    int& GetIDMax();
    void IncreaseID();
    
    //Convert the informations of Project to string type to display to screen
    string ToString();
    string PrintElement();
    //Convert the informations of Project to json type to save file
    json ToJson();
    
    friend istream& operator >> (istream&, Project&);
};
#endif