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
    int maxId;
public:
    DependentData();
    int GetMaxId();
    Dependent& Get(int);
    int GetSize();
    BusinessObject* GetPointer(int);
    void Add(Dependent&);
    void Edit(Dependent&, int);
    void Delete(int);
    void Read(string);
    int ExportToFile(string);
};
#endif