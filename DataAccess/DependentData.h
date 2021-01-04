#ifndef _DataAccess_DependentData_H_
#define _DataAccess_DependentData_H_
#include <iostream>
#include <fstream>
#include <vector>

#include "../BusinessObject/Dependent.h"
#include "DataBusinessObject.h"
#include "../libs/json.hpp"

using namespace std;
using json = nlohmann::json;

class DependentData : public DataBusinessObject{
private:
    vector<Dependent> dependentArr;

public:
    DependentData();

    //This function will point to the member of class we want to work with
    Dependent& Get(int);

    //This function will get the address of the member 
    //which we pointed by the function Get() above
    BusinessObject* GetPointer(int);

    //This fucntion will help us get the size of the vector at that time
    //after deleting or adding memeber
    int GetSize();

    //We modify our data directly by using these fucntions
    void Add(Dependent&);
    void Edit(Dependent&, int);
    void Delete(int);
    void Read(string);
    int ExportToFile(string);
};
#endif