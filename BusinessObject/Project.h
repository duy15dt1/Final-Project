//create a class to contain information about project
#ifndef _PROJECT_H_
#define _PROJECT_H_
#include <string>  
#include "BusinessObject.h"
#include "../libs/json.hpp"
using namespace std;
using json = nlohmann::json;  
class Project : public BusinessObject{
private:
    string Pname;      //Name of project
    int Pnumber;       //Serial number of project
    string Plocation;  //Location of project
    int Dnum;          //Number of department
    static int IdNew;
    int Id;
public:
    //Default constructor
    Project();         

    //Contrustor with input parameters
    Project(string Pname, int Pnumber, string Plocation, int Dnum); 
    int& GetId();
    int& GetIdNew();
    void IncreaseId();
    string ToString();
    json ToJson();
    friend istream& operator >> (istream& is, Project& pro);
};
#endif