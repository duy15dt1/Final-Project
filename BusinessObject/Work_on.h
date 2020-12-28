// Create work_on class
#ifndef _WORK_ON_H_
#define _WORK_ON_H_
#include <string>
#include "BusinessObject.h"
#include "../libs/json.hpp"
using namespace std;
using json = nlohmann::json;
class Work_on : public BusinessObject {
private:
    static int IdNew;   //    Identification of work_on sheet for update  
    int Id;             //    The current identification of work_on sheet
    int Essn;       //    Social security number of employee 
    int Pno;           //    Number of project 
    double Hours;       //    Overtime hours  
public:
    //Default constructor
    Work_on(); 
    //Contructor with input parameters     
    Work_on(int Essn, int Pno, double Hours); 
    void IncreaseId();
    //GetId() is a function that get ID value of work_on sheet
    int& GetId();
    int& GetIdNew();
    //ToString() is a function that convert the informations of work_on sheet to string type
    string ToString();
    json ToJson();
    int GetPno();
    int GetEssn();
    double GetHours();
    friend istream& operator >> (istream& is, Work_on& workon);
};
#endif 