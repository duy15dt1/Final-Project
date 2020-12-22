//create a class to contain information about project

#ifndef _PROJECT_H_
#define _PROJECT_H_
#include <string>  
using namespace std;  
class Project {
private:
    string Pname;      //Name of project
    int Pnumber;       //Serial number of project
    string Plocation;  //Location of project
    int Dnum;          //Number of department
public:
    //Default constructor
    Project();         

    //Contrustor with input parameters
    Project(string Pname, int Pnumber, string Plocation, int Dnum); //
    friend istream& operator >> (istream& os, Project& p);
    friend ostream& operator << (ostream& os, Project& p);
};
#endif