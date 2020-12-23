// Create department class
#ifndef _DEPARTMENT_H_
#define _DEPARTMENT_H_
#include <string>
using namespace std;
class Department{
private:
    static int IdNew;   //    Identification of department for update  
    int Id;             //    The current identification of department
    string Dname;       //    Name of department 
    int Dnumber;        //    Number of department 
    int Mgrssn;         //    Social security number of manager 
    string Mgrstartdate;//    Department management start date of manager
public:
    //Default constructor
    Department(); 
    //Contructor with input parameters     
    Department(string Dname, int Dnumber, int Mgrssn, string Mgrstartdate); 
    //GetId() is a function that get ID value of department 
    int GetId();
    //ToString() is a function that convert the informations of department to string type
    string ToString();
};

#endif 