#ifndef _BusinessObject_BusinessObject_H_
#define _BusinessObject_BusinessObject_H_
#include <iostream>

#include "../libs/json.hpp"

using namespace std;
using json = nlohmann::json;

class BusinessObject {
protected:
    //We created this variable to store the serial number
    //of every member in the derived classes
    int ID;
public:
    int& GetID();

    //We declare these function as virtual function because we want to
    //redefined (overidden) them in derived class to archive poymorphism
    //We will explain how to use these in derived class later
    virtual json ToJson() = 0;
    virtual string PrintElement() = 0;
};

#endif 