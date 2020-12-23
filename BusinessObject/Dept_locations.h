#ifndef _DEPT_LOCATION_H_
#define _DEPT_LOCATION_H_
#include <string>
using namespace std;
class Dept_locations {
private:
    int Dnumber;          // Number of department
    string Dlocation;     // Location of department
    int Id;
    static int Idnew;
public:
    Dept_locations();
    Dept_locations(int Dnumber, string Dlocation);
    int GetId();
    string ToString();
    friend istream& operator >> (istream& , Dept_locations& );
};

#endif