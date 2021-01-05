#include "EmployeeData.h"
#include <iostream>
#include <fstream>
#include "../libs/json.hpp"
using namespace std;

using json = nlohmann::json;

EmployeeData::EmployeeData(){
    employeeArr.resize(0);
}

int EmployeeData::GetSize() {
    return employeeArr.size();
}

//The Get(int i) function will get the data at position i of vector employeeArr
//and the GetPointer() function will get the address of that position
Employee& EmployeeData::Get(int i) {
    return employeeArr[i];
}

BusinessObject* EmployeeData::GetPointer(int i) {
    return &employeeArr[i];
}

/** @brief Function add a positional object.
 *  We increae the id in order to point to the new member.
 *  Then using push_back() function to store it at the last of the vector.
 *  @return no return
 */
void EmployeeData::Add(Employee& employee) {
    employee.IncreaseID();
    employeeArr.push_back(employee);
}

/** @brief Function edit a positional object.
 *  After locating the position of the member we want to edit.
 *  Then overwrite it by new member.
 *  @return no return
 */
void EmployeeData::Edit(Employee& employee,int i){
    employee.GetID() = employeeArr[i - 1].GetID();
    employeeArr[i - 1] = employee;
}

/** @brief Function delete a positional object.
 *  After locating the position of the member we want to delete, using erase() function to delete it.
 *  Then update the ID for current member.
 *  @return no return
 */
void EmployeeData::Delete(int i) {
    employeeArr.erase(employeeArr.begin() + i - 1);
    for (int j = i-1; j < employeeArr.size(); j++){
        employeeArr[j].GetID() = j + 1;
    }
    employeeArr.back().GetIDMax() = employeeArr.size();
}

/** @brief Function will help us to read the data
 * Function will help us to read the data
 * First, we check vector. If empty, assign sIDMax = 0
 * After, we read data and convert data to json
 * We create object from value json and push_back object into vector 
*/
void EmployeeData::Read(string filename){
    if (employeeArr.size() != 0) {
        employeeArr.back().GetIDMax() = 0;
    }
    employeeArr.resize(0);
    ifstream inFile(filename);
    string name;
    while(getline(inFile,name)) {
        json j = json::parse(name);
        string sex = j["Sex"];
        Employee employee(
            j["Fname"],
            j["Minit"],
            j["Lname"],
            j["Ssn"],
            j["Bdate"],
            j["Address"],
            sex[0],
            j["Salary"],
            j["Superssn"],
            j["Dno"]
        );
        employee.IncreaseID();
        employeeArr.push_back(employee);
    }
    inFile.close();
}
/** @brief Function export to file.
 *  First, open filename for out put.
 *  After, export member with Json format to file.
 *  Finally, close file.
 *  @return if filename exist return 1 else return 0
 */
int EmployeeData::ExportToFile(string filename){
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Employee e :employeeArr){
        outFile << e.ToJson() << endl;
    }
    outFile.close();
    return 1;
}

