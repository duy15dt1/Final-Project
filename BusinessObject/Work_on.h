// Create work_on class
#ifndef _WORK_ON_H_
#define _WORK_ON_H_
#include <string>
using namespace std;
class Work_on{
private:
    double Essn;       //    Social security number of employee 
    int Pno;           //    Number of project 
    double Hours;      //    Overtime hours  
    int Id             //    Identification of work_on sheet 
public:
    //Default constructor
    Work_on(); 

    //Contructor with input parameters     
    Work_on(double Essn, int Pno, double Hours);
    //GetId() is a function that get ID value of overtime hour sheet 
    int GetId();

    friend istream& operator >> (istream& is, Work_on& w);
    friend ostream& operator << (ostream& os, Work_on& w); 
};
#endif 