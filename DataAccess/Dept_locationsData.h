#ifndef _DATAACCESS_DEPT_LOCATIONSDATA_H_
#define _DATAACCESS_DEPT_LOCATIONSDATA_H_
#include <string>
#include <vector>
#include "../BusinessObject/Employee.h"
#include "../BusinessObject/Dept_locations.h"
using namespace std;

class Dept_locationsData {
private:
    vector<Dept_locations> _deptlocationArr;
    int _maxId;
public:
    Dept_locationsData();
    int GetMaxId();
    int PushBack(Dept_locations dept);
    Dept_locations Get(int i);
    int GetSize();
};

#endif