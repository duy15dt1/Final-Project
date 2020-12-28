#include <iostream>
#include "../DataAccess/EmployeeData.h"
#include "../DataAccess/Dept_locationsData.h"
#include "../DataAccess/DepartmentData.h"
#include "../DataAccess/Work_onData.h"
#include "../DataAccess/DependentData.h"
#include "../DataAccess/ProjectData.h"
#include <iostream>
#include <string>
using namespace std;
class UI_Choose {
private:
    EmployeeData employeedata;
    Dept_locationsData deptdata;
    Work_onData work_ondata;
    DepartmentData departmentdata;
    DependentData dependentdata;
    ProjectData projectdata;
public:
    void Display(EmployeeData& );
    void Display(Dept_locationsData& );
    void Display(DepartmentData& );
    void Display(Work_onData& );
    void Display(DependentData& );
    void Display(ProjectData& );
    void Choose_sentence();
    void ChooseTable();
    void ChooseOpt(int n);
    void DisplayAllEmpUnderSupvr(string );
    void DisplayAllEmpHasChild();
    void DisplayAverageSalaryEmpInDepartment(string& );
    void DisplayAllEmpInDepartment(int& , string&, int& );
    void DisplayManaNoDependent();
    void DisplayAllEmpNoProject();
    void TotalWorkHours(int& );
    void AverageIncomeBySex(char& );
};