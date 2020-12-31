#ifndef _UI_InOut_H_
#define _UI_InOut_H_

#include "../../BusinessObject/Department.h"
#include "../../BusinessObject/DepartmentLocations.h"
#include "../../BusinessObject/Employee.h"
#include "../../BusinessObject/Workson.h"
#include "../../BusinessObject/Dependent.h"
#include "../../BusinessObject/Project.h"
// Reference to classes of Project
#include <iostream>
using namespace std;
// Overloading extraction operator 
istream& operator >> (istream& , Employee& );
istream& operator >> (istream& , DepartmentLocations& );
istream& operator >> (istream& is, Department& d);
istream& operator >> (istream& is, Workson& d);
istream& operator >> (istream& is, Dependent& dep);
istream& operator >> (istream& is, Project& pro);
// Overloading insertion operator 

#endif