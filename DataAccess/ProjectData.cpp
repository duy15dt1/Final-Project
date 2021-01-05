#include "ProjectData.h"
#include <iostream>
#include <fstream>
#include "../libs/json.hpp"
using namespace std;
using json = nlohmann::json;

ProjectData::ProjectData() {
    projectArr.resize(0);
}


int ProjectData::GetSize() {
    return projectArr.size();
}

//The Get(int i) function will get the data at position i of vector projectArr
//and the GetPointer() function will get the address of that position
Project& ProjectData::Get(int i){
    return projectArr[i];
}

BusinessObject* ProjectData::GetPointer(int i) {
    return &projectArr[i];
}

/** @brief Function add a positional object.
 *  We increae the id in order to point to the new member.
 *  Then using push_back() function to store it at the last of the vector.
 *  @return no return
 */
void ProjectData::Add(Project& project) {
    project.IncreaseID();
    projectArr.push_back(project);
}

/** @brief Function edit a positional object.
 *  After locating the position of the member we want to edit.
 *  Then overwrite it by new member.
 *  @return no return
 */
void ProjectData::Edit(Project& project,int i) {
    project.GetID() = projectArr[i - 1].GetID();
    projectArr[i - 1] = project;
}
/** @brief Function delete a positional object.
 *  After locating the position of the member we want to delete, using erase() function to delete it.
 *  Then update the ID for current member.
 *  @return no return
 */
void ProjectData::Delete(int i) {
    projectArr.erase(projectArr.begin() + i - 1);
    for (int j = i-1; j < projectArr.size(); j++){
        projectArr[j].GetID() = j + 1;
    }
    projectArr.back().GetIDMax() = projectArr.size();
}

/** @brief Function will help us to read the data
 * Function will help us to read the data
 * First, we check vector. If empty, assign sIDMax = 0
 * After, we read data and convert data to json
 * We create object from value json and push_back object into vector 
*/
void ProjectData::Read(string filename) {
    if (projectArr.size() != 0) {
        projectArr.back().GetIDMax() = 0;
    }
    projectArr.resize(0);
    ifstream inFile(filename);
    string name;
    while(getline(inFile,name)) {
        json j = json::parse(name);
        Project p(
            j["Pname"],
            j["Pnumber"],
            j["Plocation"],
            j["Dnum"]
        );
        p.IncreaseID();
        projectArr.push_back(p);
    }
    inFile.close();
}
/** @brief Function export to file.
 *  First, open filename for out put.
 *  After, export member with Json format to file.
 *  Finally, close file.
 *  @return if filename exist return 1 else return 0
 */
int ProjectData::ExportToFile(string filename) {
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Project p :projectArr) {
        outFile << p.ToJson() << endl;
    }
    outFile.close();
    return 1;
}