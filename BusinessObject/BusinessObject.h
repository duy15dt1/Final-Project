#ifndef _BusinessObject_BusinessObject_H_
#define _BusinessObject_BusinessObject_H_
#include <iostream>

#include "../libs/json.hpp"

using namespace std;
using json = nlohmann::json;

class BusinessObject {
protected:
    int ID;
public:
    int& GetID();
    virtual string ToString() = 0;
    virtual json ToJson() = 0;
    virtual string PrintElement() = 0;
};

#endif //_BusinessObject_BusinessObject_H_