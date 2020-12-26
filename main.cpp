#include <iostream>
#include "BusinessObject/Employee.h"
#include "DataAccess/EmployeeData.h"
#include "UI/UI_Choose.h"
using namespace std;

int main() {
    UI_Choose ui;
    ui.Choose_sentence();
    return 0;
}
