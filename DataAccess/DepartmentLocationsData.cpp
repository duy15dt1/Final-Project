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

/** @brief Function add a positional object.
 *  We increae the id in order to point to the new member.
 *  Then using push_back() function to store it at the last of the vector.
 *  @return no return
 */
void DepartmentLocationsData::Add(DepartmentLocations& deptlocation) {
    deptlocation.IncreaseID();
    deptlocationArr.push_back(deptlocation);
}

/** @brief Function edit a positional object.
 *  After locating the position of the member we want to edit.
 *  Then overwrite it by new member.
 *  @return no return
 */
void DepartmentLocationsData::Edit(DepartmentLocations& deptlocation,int i) {
    deptlocation.GetID() = deptlocationArr[i - 1].GetID();
    deptlocationArr[i - 1] = deptlocation;
}
/** @brief Function delete a positional object.
 *  After locating the position of the member we want to delete, using erase() function to delete it.
 *  Then update the ID for current member.
 *  @return no return
 */
void DepartmentLocationsData::Delete(int i) {
    deptlocationArr.erase(deptlocationArr.begin() + i - 1);
    for (int j = i-1; j < deptlocationArr.size(); j++){
        deptlocationArr[j].GetID() = j + 1;
    }
    deptlocationArr.back().GetIDMax() = deptlocationArr.size();
}

/** @brief Function will help us to read the data
 * Function will help us to read the data
 * First, we check vector. If empty, assign sIDMax = 0
 * After, we read data and convert data to json
 * We create object from value json and push_back object into vector 
*/
void DepartmentLocationsData::Read(string filename) {
    if (deptlocationArr.size() != 0) {
        deptlocationArr.back().GetIDMax() = 0;
    }
    deptlocationArr.resize(0);
    ifstream inFile(filename);
    string name;
    while(getline(inFile,name)) {
        json j = json::parse(name);
        DepartmentLocations deptlocation(
            j["Dnumber"],
            j["Dlocation"]
        );
        deptlocation.IncreaseID();
        deptlocationArr.push_back(deptlocation);
    }
    inFile.close();
}

/** @brief Function export to file.
 *  First, open filename for out put.
 *  After, export member with Json format to file.
 *  Finally, close file.
 *  @return if filename exist return 1 else return 0
 */
int DepartmentLocationsData::ExportToFile(string filename) {
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (DepartmentLocations deptlocation:deptlocationArr) {
        outFile << deptlocation.ToJson() << endl;
    }
    outFile.close();
    return 1;
}