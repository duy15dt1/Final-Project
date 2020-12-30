#ifndef _DataAccess_DataBusinessObject_H_
#define _DataAccess_DataBusinessObject_H_
#include <iostream>
#include "../BusinessObject/BusinessObject.h"
using namespace std;
class DataBusinessObject {
public:
    virtual int GetSize() = 0;
    virtual BusinessObject* GetPointer(int ) = 0;
};

#endif