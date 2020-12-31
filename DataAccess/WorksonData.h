#ifndef _DATAACCESS_WORK_ON_DATA_H_
#define _DATAACCESS_WORK_ON_DATA_H_
#include <iostream>
#include <fstream>
#include <vector>

#include "../BusinessObject/Workson.h"
#include "DataBusinessObject.h"
#include "../libs/json.hpp"

using namespace std;
using json = nlohmann::json;

class WorksonData : public DataBusinessObject {
private:
    vector <Workson> worksonArr;
    int maxID;
public:
    //Contructor function of Workson_Data
    WorksonData();
    //GetMaxId() is a function that get the maximum ID of Workson data
    int GetMaxId();
    // PushBack(Workson) is a function that push one Workson data in the back of _data vector and return maximun ID of the current _data vector
    //Get(int i) is a function that get the Workson data at i position of _data vector
    Workson& Get(int );
    BusinessObject* GetPointer(int);
    int GetSize();
    void Add(Workson&);
    void Edit(Workson&, int);
    void Delete(int);
    void Read(string);
    int ExportToFile(string);
};    

#endif