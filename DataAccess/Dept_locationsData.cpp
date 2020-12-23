#include "Dept_locationsData.h"

Dept_locationsData::Dept_locationsData() {
    _deptlocationArr.resize(0);
    _maxId = 0;
}
int Dept_locationsData::GetMaxId() {
    return _maxId;
}
int Dept_locationsData::PushBack(Dept_locations dept) {
    if (_maxId < dept.GetId()) {
        _maxId = dept.GetId();
    }
    _deptlocationArr.push_back(dept);
    return _maxId;
}
Dept_locations Dept_locationsData::Get(int i) {
    return _deptlocationArr[i];
}
int Dept_locationsData::GetSize() {
    return _deptlocationArr.size();
}