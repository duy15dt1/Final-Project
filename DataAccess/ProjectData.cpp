#include "ProjectData.h"

ProjectData::ProjectData(){
    _maxId = 0;
    _data.resize(0);
}

int ProjectData::GetMaxId(){
    return _maxId;
}

int ProjectData::PushBack(Project p){
    if (_maxId < p.GetId()){
        _maxId = p.GetId();
    }
    _data.push_back(p);
    return _maxId;
}

Project ProjectData::Get(int i){
    return _data[i];
}