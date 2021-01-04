#include "DepartmentLocationsData.h"

DepartmentLocationsData::DepartmentLocationsData() {
    deptlocationArr.resize(0);
}

int DepartmentLocationsData::GetSize() {
    return deptlocationArr.size();
}

//The Get(int i) function will get the data at position i of vector deptlocationArr
//and the GetPointer() function will get the address of that position
DepartmentLocations& DepartmentLocationsData::Get(int i) {
    return deptlocationArr[i];
}

BusinessObject* DepartmentLocationsData::GetPointer(int i) {
    return &deptlocationArr[i];
}

//We increae the id in order to point to the new member
//then using push_back() function to store it at the last of the vector
void DepartmentLocationsData::Add(DepartmentLocations& deptlocation) {
    deptlocation.IncreaseID();
    deptlocationArr.push_back(deptlocation);
}

//After locating the position of the member we want to edit
//Overwrite them by the new member
void DepartmentLocationsData::Edit(DepartmentLocations& deptlocation,int i) {
    deptlocation.GetID() = deptlocationArr[i].GetID();
    deptlocationArr[i] = deptlocation;
}

void DepartmentLocationsData::Delete(int i) {
    deptlocationArr.erase(deptlocationArr.begin() + i - 1);
    for (int j = i-1; j < deptlocationArr.size(); j++){
        deptlocationArr[j].GetID() = j + 1;
    }
    deptlocationArr.back().GetIDMax() = deptlocationArr.size();
}

void DepartmentLocationsData::Read(string filename) {
    if (deptlocationArr.size() != 0) {
        deptlocationArr.back().GetIDMax() = 0;
    }
    deptlocationArr.resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize]; 
    while (inFile.getline(buff,maxSize)) {
        json j = json::parse(buff);
        DepartmentLocations deptlocation(
            j["Dnumber"],
            j["Dlocation"]
        );
        deptlocation.IncreaseID();
        deptlocationArr.push_back(deptlocation);
    }
    inFile.close();
}


int DepartmentLocationsData::ExportToFile(string filename) {
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (DepartmentLocations deptlocation:deptlocationArr) {
        outFile << deptlocation.ToJson() << endl;
    }
    outFile.close();
    return 1;
}