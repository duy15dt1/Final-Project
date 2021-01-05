#include "WorksonData.h"
#include <iostream>
#include <fstream>
#include "../libs/json.hpp"
using namespace std;
using json = nlohmann::json;

WorksonData::WorksonData(){
    worksonArr.resize(0);
}

int WorksonData::GetSize() {
    return worksonArr.size();
}

//The Get(int i) function will get the data at position i of vector worksonArr
//and the GetPointer() function will get the address of that position
Workson& WorksonData::Get(int i) {
    return worksonArr[i];
}
BusinessObject* WorksonData::GetPointer(int i) {
    return &worksonArr[i];
}

/** @brief Function add a positional object.
 *  We increae the id in order to point to the new member.
 *  Then using push_back() function to store it at the last of the vector.
 *  @return no return
 */
void WorksonData::Add(Workson& workson) {
    workson.IncreaseID();
    worksonArr.push_back(workson);
}

/** @brief Function edit a positional object.
 *  After locating the position of the member we want to edit.
 *  Then overwrite it by new member.
 *  @return no return
 */
void WorksonData::Edit(Workson& workson,int i) {
    workson.GetID() = worksonArr[i - 1].GetID();
    worksonArr[i - 1] = workson;
}
/** @brief Function delete a positional object.
 *  After locating the position of the member we want to delete, using erase() function to delete it.
 *  Then update the ID for current member.
 *  @return no return
 */
void WorksonData::Delete(int i){
    worksonArr.erase(worksonArr.begin()+i-1);
    for (int j = i-1; j < worksonArr.size() ; j++ ){
        worksonArr[j].GetID() = j + 1; 
    } 
    worksonArr.back().GetIDMax() = worksonArr.size();
}

/** @brief Function will help us to read the data
 * Function will help us to read the data
 * First, we check vector. If empty, assign sIDMax = 0
 * After, we read data and convert data to json
 * We create object from value json and push_back object into vector 
*/
void WorksonData::Read(string filename) {
    if(worksonArr.size() != 0){
        worksonArr.back().GetIDMax() = 0;
    }
    worksonArr.resize(0);
    ifstream inFile(filename);
    string name;
    while(getline(inFile,name)) {
        json j = json::parse(name);
        Workson work(
            j["Essn"],
            j["Pno"],
            j["Hours"]
        );
        work.IncreaseID();
        worksonArr.push_back(work);
    }
    inFile.close();
}
/** @brief Function export to file.
 *  First, open filename for out put.
 *  After, export member with Json format to file.
 *  Finally, close file.
 *  @return if filename exist return 1 else return 0
 */
int WorksonData::ExportToFile(string filename) {
    ofstream outFile(filename,ios::out);
    if(!outFile) return 0;
    for (Workson work : worksonArr) {
        outFile << work.ToJson() << endl;
    }  
    outFile.close();
    return 1;
}