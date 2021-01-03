#ifndef _DataAccess_DataBusinessObject_H_
#define _DataAccess_DataBusinessObject_H_
#include <iostream>

#include "../BusinessObject/BusinessObject.h"

using namespace std;

class DataBusinessObject {
public:
    //We declare these function as virtual function because we want to
    //redefined (overidden) them in derived class to archive poymorphism
    //We will explain how to use these in derived class later
    virtual int GetSize() = 0;
    virtual BusinessObject* GetPointer(int ) = 0;
};

#endif