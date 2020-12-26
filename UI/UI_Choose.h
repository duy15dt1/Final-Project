#include <iostream>
#include "../BusinessObject/Employee.h"
#include "../DataAccess/EmployeeData.h"
#include <iostream>
#include <string>
using namespace std;
class UI_Choose {
private:
    EmployeeData employeedata;
public:
    void DisplayEmployees(EmployeeData& );
    void Choose_sentence();
    void ChooseTable();
    void ChooseOpt(int n);
};