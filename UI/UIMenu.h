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

    //There are 10 tasks to do in this project
    //Using this fucntion to choose which tasks we want the program to process
    void ChooseSentence();

    //After choosing the task, we use this fucntion 
    //to choose the class we want to modify the data
    void ChooseTable();

    //Using this fucntion to Add/Edit/Delete/Read the data of the class we already chose
    void ChooseOpt(int n);


    void DisplayAllEmpUnderSupvr(string);
    void DisplayAllEmpHasChild();
    void DisplayAverageSalaryEmpInDepartment(string&);
    void DisplayAllEmpInDepartment(int& , string&, int&);
    void DisplayManaNoDependent();
    void DisplayAllEmpNoProject();
    void TotalWorkHours(int&);
    void AverageIncomeBySex(char&);
    void SaveFile(string& foldername);
    vector<string> GetNameBackUpFile();
    void BackUpFile(string& foldername);
};