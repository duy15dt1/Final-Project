#ifndef _DEPT_LOCATION_H_
#define _DEPT_LOCATION_H_
#include <string>   
#include "../libs/json.hpp"
#include "BusinessObject.h"
using namespace std;
using json = nlohmann::json;
class Dept_locations : public BusinessObject {
private:
    int Dnumber;          // Number of department
    string Dlocation;     // Location of department
    int Id;
    static int Idnew;
public:
    Dept_locations();
    Dept_locations(int Dnumber, string Dlocation);
    void IncreaseId();
    int& GetId();
    int& GetIdNew();
    json ToJson();
    string ToString();
    friend istream& operator >> (istream& , Dept_locations& );
};

#endif