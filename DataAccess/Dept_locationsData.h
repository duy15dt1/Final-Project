#ifndef _DATAACCESS_DEPT_LOCATIONSDATA_H_
#define _DATAACCESS_DEPT_LOCATIONSDATA_H_
#include <string>
#include <vector>
#include "../BusinessObject/Employee.h"
#include "../BusinessObject/Dept_locations.h"
#include "DataBusinessObject.h"
#include "../libs/json.hpp"
#include <fstream>
using namespace std;

class Dept_locationsData : public DataBusinessObject {
private:
    vector<Dept_locations> _deptlocationArr;
    int _maxId;
public:
    Dept_locationsData();
    int GetMaxId();
    Dept_locations& Get(int i);
    BusinessObject* GetPointer(int );
    int GetSize();
    void Add(Dept_locations&);
    void Edit(int );
    void Delete(int );
    void Read(string );
    int ExportToFile(string );
};

#endif