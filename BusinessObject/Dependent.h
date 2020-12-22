//create a class to contain information about dependent

#ifndef _DEPENDENT_H_
#define _DEPENDENT_H_
#include <string>    
using namespace std;
class Dependent {
private:
    double Essn;                    //Social security number of employee
    string Dependent_name;          //Name of dependent
    char Sex;                       //Sex of dependent
    string Bdate;                   //Date of birth of employee
    string Relationship;            //Relationship of dependent
public:
    //Default constructor
    Dependent();         

    //Contrustor with input parameters
    Dependent(double Essn, string Dependent_name, char Sex, string Bdate, string Relationship); //
    friend istream& operator >> (istream& os, Dependent& d);
    friend ostream& operator << (ostream& os, Dependent& d);
};
#endif