#include "InOut.h"
// Overloading extraction operator 

istream& operator >> (istream& is, Employee& emp) {   
    is.ignore();       
    cout << "First name of employee "; getline(is, emp.Fname);
    cout << "Middle nane of employee "; is >> emp.Minit;
    is.ignore();
    cout << "Last name of employee "; getline(is, emp.Fname);
    cout << "Social security number of employee "; is >> emp.Ssn;
    cout << "Birthday of employee "; getline(is, emp.Bdate);
    cout << "Address of employee "; getline(is, emp.Address);
    cout << "Sex of employee "; is >> emp.Sex;
    cout << "Salary of employee "; is >> emp.Salary;
    cout << "SuperSSN of employee "; is >> emp.Superssn;
    cout << "Department Number of employee "; is >> emp.Dno;
    return is;
}
