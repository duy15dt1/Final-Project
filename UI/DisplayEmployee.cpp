#include "DisplayEmployee.h"

void AddEmployee(EmployeeData& employeeData) {
    Employee e1("John", "B", "Smith", 123456789, "1965-01-09", "73 Fondren, Houston, TX", 'M', 30000, 333445555, 5);
    Employee e2("Franklin", "T", "Wong", 333445555, "1955-12-08", "638 Voss, Houston, TX", 'M', 40000, 888665555, 5);
    Employee e3("Alicia", "J", "Zelaya", 999887777, "1968-07-19", "3321 Castle, String, TX", 'F', 25000, 987654321, 4);
    Employee e4("Ramesh", "K", "Narayan", 666884444, "1962-09-15", "975 Fire Oak, Humble, TX", 'M', 38000, 333445555, 5);
    Employee e5("Joyce", "A", "English", 111222333, "1972-07-31", "5631 Rice, Houston, TX", 'F', 25000, 333445555, 5);
    Employee e6("Joyce", "A", "English", 453453453, "1972-07-31", "5631 Rice, Houston, TX", 'F', 25000, 333445555, 5);
    Employee e7("Ahmad", "V", "Jabbar", 987987987, "1969-03-29", "980 Dallas, Houston, TX", 'M', 25000, 987654321, 4);
    Employee e8("James", "E", "Borg", 888665555, "1937-11-10", "450 Stone, Houston, TX", 'M', 55000, 0, 1);
    employeeData.PushBack(e1);
    employeeData.PushBack(e2);
    employeeData.PushBack(e3);
    employeeData.PushBack(e4);
    employeeData.PushBack(e5);
    employeeData.PushBack(e6);
    employeeData.PushBack(e7);
    employeeData.PushBack(e8);
    
}

void DisplayEmployees(EmployeeData& employeeData) {
    for (int i = 0; i < employeeData.GetSize(); i++) {
        Employee e = employeeData.Get(i);
        cout << e.GetId() << " " << e.ToString() << endl << endl;
    }
}