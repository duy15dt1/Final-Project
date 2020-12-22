#include "Project.h"

Project::Project(){
    Pname = "";     
    Pnumber = 0;       
    Plocation = ""; 
    Dnum = 0;          
};

Project::Project(string Pname, int Pnumber, string Plocation, int Dnum){
    this->Pname = Pname;    
    this->Pnumber = Pnumber;    
    this->Plocation = Plocation;  
    this->Dnum = Dnum;         
};