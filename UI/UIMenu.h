#include <iostream>
#include <string>
#include <direct.h>
#include "../DataAccess/EmployeeData.h"
#include "../DataAccess/DepartmentLocationsData.h"
#include "../DataAccess/DepartmentData.h"
#include "../DataAccess/WorksonData.h"
#include "../DataAccess/DependentData.h"
#include "../DataAccess/ProjectData.h"

using namespace std;

class UIMenu {
private:
    EmployeeData employeedata;
    DepartmentLocationsData departmentlocationsdata;
    WorksonData worksondata;
    DepartmentData departmentdata;
    DependentData dependentdata;
    ProjectData projectdata;
public:
    void Display(DataBusinessObject*);
    void ChooseSentence();
    void ChooseTable();
    void ChooseOpt(int n);
    void DisplayAllEmpUnderSupvr(string);
    void DisplayAllEmpHasChild();
    void DisplayAverageSalaryEmpInDepartment(string&);
    void DisplayAllEmpInDepartment(int& , string&, int&);
    void DisplayManaNoDependent();
    void DisplayAllEmpNoProject();
    void TotalWorkHours(int&);
    void AverageIncomeBySex(char&);
};