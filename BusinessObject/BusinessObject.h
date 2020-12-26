#ifndef _BusinessObject_BusinessObject_H_
#define _BusinessObject_BusinessObject_H_
#include <iostream>
#include "../libs/json.hpp"
using namespace std;
using json = nlohmann::json;
class BusinessObject {
public:
    virtual void IncreaseId() = 0;
    virtual int& GetId() = 0;
    virtual string ToString() = 0;
    virtual json ToJson() = 0;
};

#endif