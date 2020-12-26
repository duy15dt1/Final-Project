#ifndef _DataAccess_DataBusinessObject_H_
#define _DataAccess_DataBusinessObject_H_
#include <iostream>
#include "../BusinessObject/BusinessObject.h"
using namespace std;
class DataBusinessObject {
public:
    virtual void Add() = 0;
    virtual void Edit(int ) = 0;
    virtual void Delete(int ) = 0;
    virtual void Read(string ) = 0;
};

#endif