#include "DependentData.h"

DependentData::DependentData() {
    dependentArr.resize(0);
}

int DependentData::GetSize(){
    return dependentArr.size();
}

//The Get(int i) function will get the data at position i of vector dependentArr
//and the GetPointer() function will get the address of that position
Dependent& DependentData::Get(int i){
    return  dependentArr[i];
}

BusinessObject* DependentData::GetPointer(int i) {
    return &dependentArr[i];
}

/** @brief Function add a positional object.
 *  We increae the id in order to point to the new member.
 *  Then using push_back() function to store it at the last of the vector.
 *  @return no return
 */
void DependentData::Add(Dependent& dependent) {
    dependent.IncreaseID();
    dependentArr.push_back(dependent);
}
/** @brief Function edit a positional object.
 *  After locating the position of the member we want to edit.
 *  Then overwrite it by new member.
 *  @return no return
 */
void DependentData::Edit(Dependent& dependent,int i) {
    dependent.GetID() = dependentArr[i - 1].GetID();
    dependentArr[i - 1] = dependent;
}
/** @brief Function delete a positional object.
 *  After locating the position of the member we want to delete, using erase() function to delete it.
 *  Then update the ID for current member.
 *  @return no return
 */
void DependentData::Delete(int i) {
    dependentArr.erase(dependentArr.begin() + i - 1);
    for (int j = i-1; j < dependentArr.size(); j++){
        dependentArr[j].GetID() = j + 1;
    }
    dependentArr.back().GetIDMax() = dependentArr.size();
}

/** @brief Function will help us to read the data
 * Function will help us to read the data
 * First, we check vector. If empty, assign sIDMax = 0
 * After, we read data and convert data to json
 * We create object from value json and push_back object into vector 
*/
void DependentData::Read(string filename) {
    if (dependentArr.size() != 0) {
        dependentArr.back().GetIDMax() = 0;
    }
    dependentArr.resize(0);
    ifstream inFile(filename);
    string name;
    while(getline(inFile,name)) {
        json j = json::parse(name);
        string sex = j["Sex"];
        Dependent d(
            j["Essn"],
            j["Dependent_name"],
            sex[0],
            j["Bdate"],
            j["Relationship"]
        );
        d.IncreaseID();
        dependentArr.push_back(d);
    }
    inFile.close();
}
/** @brief Function export to file.
 *  First, open filename for out put.
 *  After, export member with Json format to file.
 *  Finally, close file.
 *  @return if filename exist return 1 else return 0
 */
int DependentData::ExportToFile(string filename) {
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Dependent d :dependentArr){
        outFile << d.ToJson() <<endl;
    }
    outFile.close();
    return 1;
}