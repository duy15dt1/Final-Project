#ifndef _BusinessObject_BusinessObject_H_
#define _BusinessObject_BusinessObject_H_
#include <iostream>
using namespace std;
class BusinessObject {
public:
    virtual void IncreaseId() = 0;
    virtual int& GetId() = 0;
    virtual string ToString() = 0;
};

#endif