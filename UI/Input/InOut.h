#ifndef _INOUT_H_
#define _INOUT_H_

#include "../../BusinessObject/Employee.h"
// Reference to classes of Project
#include <iostream>
#include <vector>
using namespace std;
// Overloading extraction operator 
istream& operator >> (istream& is, Employee& d);

// Overloading insertion operator 
ostream& operator << (ostream& os, Employee& d);

#endif