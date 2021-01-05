#include "DepartmentData.h"
DepartmentData::DepartmentData() {
    departmentArr.resize(0);
}

//The Get(int i) function will get the data at position i of vector departmentArr
//and the GetPointer() function will get the address of that position
Department& DepartmentData::Get(int i) {
    return departmentArr[i];
}

BusinessObject* DepartmentData::GetPointer(int i) {
    return &departmentArr[i];
}

int DepartmentData::GetSize() {
    return departmentArr.size();
}

/** @brief Function add a positional object.
 *  We increae the id in order to point to the new member.
 *  Then using push_back() function to store it at the last of the vector.
 *  @return no return
 */
void DepartmentData::Add(Department& deparment) {
    deparment.IncreaseID();
    departmentArr.push_back(deparment);
}

/** @brief Function delete a positional object.
 *  After locating the position of the member we want to delete, using erase() function to delete it.
 *  Then update the ID for current member.
 *  @return no return
 */
void DepartmentData::Edit(Department& deparment,int i) {
    deparment.GetID() = departmentArr[i - 1].GetID();
    departmentArr[i - 1] = deparment;
}

void DepartmentData::Delete(int i) {
    departmentArr.erase(departmentArr.begin()+i-1);
    for (int j = i-1; j < departmentArr.size(); j++ ){
        departmentArr[j].GetID() = j + 1; 
    } 
    departmentArr.back().GetIDMax() = departmentArr.size();
}

/** @brief Function will help us to read the data
 * Function will help us to read the data
 * First, we check vector. If empty, assign sIDMax = 0
 * After, we read data and convert data to json
 * We create object from value json and push_back object into vector 
*/
void DepartmentData::Read(string filename) {
    if(departmentArr.size() != 0 ){
        departmentArr.back().GetIDMax() = 0;
    }
    departmentArr.resize(0);
    ifstream inFile(filename);
    string name;
    while(getline(inFile,name)) {
        json j = json::parse(name);
        Department department(
            j["Dname"],
            j["Dnumber"],
            j["Mgrssn"],
            j["Mgrstartdate"]
        );
        department.IncreaseID();
        departmentArr.push_back(department);
    }
    inFile.close();
}
/** @brief Function export to file.
 *  First, open filename for out put.
 *  After, export member with Json format to file.
 *  Finally, close file.
 *  @return if filename exist return 1 else return 0
 */
int DepartmentData::ExportToFile(string filename) {
    ofstream outFile(filename,ios::out);
    if(!outFile) return 0;
    for( Department department:departmentArr) {
        outFile << department.ToJson() << endl;
    }
    outFile.close();
    return 1;
}