#include "DisplayDepartment.h"

void DisplayDepartment(DepartmentData& departmentdata){
    for (int i = 0; i < departmentdata.GetMaxId();i++){
        Department temp;
        temp = departmentdata.Get(i);
        cout <<temp.GetId()<<temp.ToString()<<endl;
    }
}