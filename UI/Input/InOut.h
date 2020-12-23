#ifndef _INOUT_H_
#define _INOUT_H_

#include "../../BusinessObject/Department.h"
#include "../../BusinessObject/Dependent.h"
#include "../../BusinessObject/Dept_locations.h"
#include "../../BusinessObject/Employee.h"
#include "../../BusinessObject/Project.h"
#include "../../BusinessObject/Work_on.h"
// Reference to classes of Project
#include <iostream>
#include <vector>
using namespace std;
// Overloading extraction operator 
istream& operator >> (istream& is, Department& d);
istream& operator >> (istream& is, Dependent& d);
istream& operator >> (istream& is, Dept_locations& d);
istream& operator >> (istream& is, Employee& d);
istream& operator >> (istream& is, Project& d);
istream& operator >> (istream& is, Work_on& d);
// Overloading insertion operator 
ostream& operator << (ostream& os, Department& d);
ostream& operator << (ostream& os, Dependent& d);
ostream& operator << (ostream& os, Dept_locations& d);
ostream& operator << (ostream& os, Employee& d);
ostream& operator << (ostream& os, Project& d);
ostream& operator << (ostream& os, Work_on& d);

#endif