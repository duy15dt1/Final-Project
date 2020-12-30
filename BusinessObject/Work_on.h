//Class contains all information of object Work on
#ifndef _WORK_ON_H_
#define _WORK_ON_H_
#include <string>
#include "BusinessObject.h"
#include "../libs/json.hpp"
using namespace std;
using json = nlohmann::json;
class Work_on : public BusinessObject {
private:
    //Original member of the class
    int Essn;           // Social security number of employee 
    int Pno;            // Number of project 
    double Hours;       // Overtime hours

    //Objects of the class has no serial number so we add the variable Id
    //to access the object whenever we want.
    //The IdNew exists because when we add or delete an object in the class
    //we will use this variable to identify the new serial number of the object
    int Id;             // The current identification of Work_on sheet 
    static int IdNew;   // Identification of Work_on sheet for update   
public:
    Work_on();     
    Work_on(int Essn, int Pno, double Hours); 

    //All 3 methods below are private so we declare these functions 
    //to return the value of Pno, Essn, Hours to use in another method
    int GetPno();
    int GetEssn();
    double GetHours();

   
    int& GetId();
    int& GetIdNew();
    void IncreaseId();
    
    
    //Convert the informations of Work_on to string type to display to screen
    string ToString();

    //Convert the informations of Work_on to json type to save file
    json ToJson();

    friend istream& operator >> (istream& is, Work_on& workon);
};
#endif 