#ifndef _INOUT_H_
#define _INOUT_H_

#include "../../BusinessObject/Employee.h"
#include "../../BusinessObject/Department.h"
#include "../../BusinessObject/Work_on.h"
// Reference to classes of Project
#include <iostream>
#include <vector>
using namespace std;
// Overloading extraction operator 
istream& operator >> (istream& is, Employee& d);
istream& operator >> (istream& is, Department& depa);
istream& operator >> (istream& is, Work_on& workon);
// Overloading insertion operator 
ostream& operator << (ostream& os, Employee& d);

#endif