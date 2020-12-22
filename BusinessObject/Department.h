// Create department class
#ifndef _DEPARTMENT_H_
#define _DEPARTMENT_H_
#include <string>
using namespace std;
class Department{
private:
    string Dname;       //    Name of department 
    int Dnumber;        //    Number of department 
    double Mgrssn;      //    Social security number of manager 
    string Mgrstartdate;//    Department management start date of manager 
public:
    //Default constructor
    Department(); 

    //Contructor with input parameters     
    Department(string Dname, int Dnumber, double Mgrssn, string Mgrstartdate); 
    friend istream& operator >> (istream& is, Department& d);
    friend ostream& operator << (ostream& is, Department& d);
};

#endif 