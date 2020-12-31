#include "ProjectData.h"
#include <iostream>
#include <fstream>
#include "../libs/json.hpp"
using namespace std;
using json = nlohmann::json;

ProjectData::ProjectData() {
    maxID = 0;
    projectArr.resize(0);
}
void ProjectData::Read(string filename) {
    if (projectArr.size() != 0) {
        projectArr.back().GetIDMax() = 0;
    }
    maxID = 0;
    projectArr.resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize]; 
    while (inFile.getline(buff,maxSize)) {
        json j = json::parse(buff);
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

void ProjectData::Delete(int i) {
    projectArr.erase(projectArr.begin() + i - 1);
    maxID = projectArr.size();
    for (int j = i-1; j < maxID; j++){
        projectArr[j].GetID() = j + 1;
    }
    projectArr.back().GetIDMax() = maxID;
}

void ProjectData::Add(Project& project) {
    project.IncreaseID();
    projectArr.push_back(project);
}

void ProjectData::Edit(Project& project,int i) {
    project.GetID() = projectArr[i].GetID();
    projectArr[i] = project;
}

int ProjectData::GetMaxID(){
    return maxID;
}


Project& ProjectData::Get(int i){
    return projectArr[i];
}

BusinessObject* ProjectData::GetPointer(int i) {
    return &projectArr[i];
}

int ProjectData::GetSize() {
    return projectArr.size();
}

int ProjectData::ExportToFile(string filename) {
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Project p :projectArr) {
        outFile << p.ToJson() << endl;
    }
    outFile.close();
    return 1;
}