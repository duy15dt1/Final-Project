#include "DisplayDept_locations.h"

void AddDept_locations() {
    Dept_locations dept1(1, "Houston");
    Dept_locations dept2(4, "Stafford");
    Dept_locations dept3(5, "Bellaire");
    Dept_locations dept4(5, "Sugarland");
    Dept_locations dept5(5, "Houston");
    Dept_locationsData dept_locationsData;
    dept_locationsData.PushBack(dept1);
    dept_locationsData.PushBack(dept2);
    dept_locationsData.PushBack(dept3);
    dept_locationsData.PushBack(dept4);
    dept_locationsData.PushBack(dept5);
    DisplayDept_locations(dept_locationsData);
}

void DisplayDept_locations(Dept_locationsData& dept) {
    for (int i = 0; i < dept.GetSize(); i++) {
        Dept_locations d = dept.Get(i);
        cout << d.GetId() << " " << d.ToString() << endl << endl;
    }
}