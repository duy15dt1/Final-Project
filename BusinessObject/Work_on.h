// Create work_on class
#ifndef _WORK_ON_H_
#define _WORK_ON_H_
#include <string>
using namespace std;
class Work_on{
private:
    static int IdNew;   //    Identification of work_on sheet for update  
    int Id;             //    The current identification of work_on sheet
    double Essn;       //    Social security number of employee 
    int Pno;           //    Number of project 
    float Hours;      //    Overtime hours  
public:
    //Default constructor
    Work_on(); 
    //Contructor with input parameters     
    Work_on(double Essn, int Pno, double Hours);
    //GetId() is a function that get ID value of work_on sheet 
    int GetId();
    //ToString() is a function that convert the informations of work_on sheet to string type
    string ToString();
};
#endif 