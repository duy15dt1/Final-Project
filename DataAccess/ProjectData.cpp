#include "ProjectData.h"
#include <iostream>
#include <fstream>
#include "../libs/json.hpp"
using namespace std;
using json = nlohmann::json;

ProjectData::ProjectData(){
    _maxId = 0;
    _projectArr.resize(0);
}


void ProjectData::Read(string filename){
    if (_projectArr.size() != 0) {
        _projectArr.back().GetIdNew() = 0;
    }
    _maxId = 0;
    _projectArr.resize(0);
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
        p.IncreaseId();
        _projectArr.push_back(p);
    }
    inFile.close();
}

void ProjectData::Delete(int i) {
    _projectArr.erase(_projectArr.begin() + i - 1);
    _maxId = _projectArr.size();
    for (int j = i-1; j < _maxId; j++){
        _projectArr[j].GetId() = j + 1;
    }
    _projectArr.back().GetIdNew() = _maxId;
}

void ProjectData::Add(Project& project) {
    project.IncreaseId();
    _projectArr.push_back(project);
}

void ProjectData::Edit(int i) {
    cin >> _projectArr[i];
}

int ProjectData::GetMaxId(){
    return _maxId;
}


Project& ProjectData::Get(int i){
    return _projectArr[i];
}

BusinessObject* ProjectData::GetPointer(int i) {
    return &_projectArr[i];
}

int ProjectData::GetSize() {
    return _projectArr.size();
}

int ProjectData::ExportToFile(string filename){
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Project p :_projectArr){
        outFile << p.ToJson() << endl;
    }
    outFile.close();
    return 1;
}