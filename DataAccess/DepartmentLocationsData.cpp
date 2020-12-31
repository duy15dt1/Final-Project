#include "DepartmentLocationsData.h"

DepartmentLocationsData::DepartmentLocationsData() {
    deptlocationArr.resize(0);
    maxID = 0;
}
int DepartmentLocationsData::GetMaxID() {
    return maxID;
}
DepartmentLocations& DepartmentLocationsData::Get(int i) {
    return deptlocationArr[i];
}
int DepartmentLocationsData::GetSize() {
    return deptlocationArr.size();
}
BusinessObject* DepartmentLocationsData::GetPointer(int i) {
    return &deptlocationArr[i];
}

void DepartmentLocationsData::Read(string filename) {
    if (deptlocationArr.size() != 0) {
        deptlocationArr.back().GetIDMax() = 0;
    }
    maxID = 0;
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

void DepartmentLocationsData::Delete(int i) {
    deptlocationArr.erase(deptlocationArr.begin() + i - 1);
    maxID = deptlocationArr.size();
    for (int j = i-1; j < maxID; j++){
        deptlocationArr[j].GetID() = j + 1;
    }
    deptlocationArr.back().GetIDMax() = maxID;
}

void DepartmentLocationsData::Add(DepartmentLocations& deptlocation) {
    deptlocation.IncreaseID();
    deptlocationArr.push_back(deptlocation);
}

void DepartmentLocationsData::Edit(DepartmentLocations& deptlocation,int i) {
    deptlocation.GetID() = deptlocationArr[i].GetID();
    deptlocationArr[i] = deptlocation;
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