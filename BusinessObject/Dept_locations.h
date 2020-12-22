#ifndef _DEPT_LOCATION_H_
#define _DEPT_LOCATION_H_
#include <string>
using namespace std;
class Dept_locations {
private:
    int Dnumber;          // Number of department
    string Dlocation;     // Location of department
public:
    Dept_locations();
    Dept_locations(int Dnumber, string Dlocation);
    friend istream& operator >> (istream& is, Dept_locations& d);
    friend ostream& operator << (ostream& os, Dept_locations& d);
};

#endif