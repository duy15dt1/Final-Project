//create a class to contain information about dependent
#ifndef _DEPENDENT_H_
#define _DEPENDENT_H_
#include <string>
#include "BusinessObject.h"
#include "../libs/json.hpp" 
using namespace std;
using json = nlohmann::json;
class Dependent : public BusinessObject{
private:
    int Essn;                       //Social security number of employee
    string Dependent_name;          //Name of dependent
    char Sex;                       //Sex of dependent
    string Bdate;                   //Date of birth of employee
    string Relationship;            //Relationship of dependent
    static int IdNew;
    int Id;
public:
    //Default constructor
    Dependent();         

    //Contrustor with input parameters
    Dependent(int Essn, string Dependent_name, char Sex, string Bdate, string Relationship);
    int& GetId();
    int& GetIdNew();
    string ToString();
    void IncreaseId();
    json ToJson();
    friend istream& operator >> (istream& is, Dependent& dep);
};

#endif