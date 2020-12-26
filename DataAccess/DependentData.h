#ifndef _DATAACCESS_DEPENDENT_DATA_H_
#define _DATAACCESS_DEPENDENT_DATA_H_
#include <vector>
#include "../BusinessObject/Dependent.h"
#include "DataBusinessObject.h"

class DependentData : public DataBusinessObject{
private:
    vector<Dependent> _dependentArr;
    int _maxId;
public:
    DependentData();
    int GetMaxId();
    int PushBack(Dependent);
    Dependent& Get(int );
    int GetSize();
    void Add();
    void Edit(int );
    void Delete(int );
    void Read(string );
    int ExportToFile(string );
};
#endif