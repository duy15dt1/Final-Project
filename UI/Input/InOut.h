#ifndef _INOUT_H_
#define _INOUT_H_

#include "../../BusinessObject/Department.h"
#include "../../BusinessObject/Dept_locations.h"
#include "../../BusinessObject/Employee.h"
#include "../../BusinessObject/Work_on.h"
#include "../../BusinessObject/Dependent.h"
#include "../../BusinessObject/Project.h"
// Reference to classes of Project
#include <iostream>
using namespace std;
// Overloading extraction operator 
istream& operator >> (istream& , Employee& );
istream& operator >> (istream& , Dept_locations& );
istream& operator >> (istream& is, Department& d);
istream& operator >> (istream& is, Work_on& d);
istream& operator >> (istream& is, Dependent& dep);
istream& operator >> (istream& is, Project& pro);
// Overloading insertion operator 

#endif