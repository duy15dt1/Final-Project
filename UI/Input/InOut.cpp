#include "InOut.h"
// Overloading extraction operator 

istream& operator >> (istream& is, Employee& employee) {          
    cout << "First name of employee: "; getline(is, employee.Fname);
    cout << "Middle nane of employee: "; getline(is,employee.Minit);
    cout << "Last name of employee: "; getline(is, employee.Lname);
    cout << "Social security number of employee: "; is >> employee.Ssn; is.ignore();
    cout << "Birthday of employee: "; getline(is, employee.Bdate);
    cout << "Address of employee: "; getline(is, employee.Address);
    cout << "Sex of employee: "; is >> employee.Sex;
    cout << "Salary of employee: "; is >> employee.Salary;
    cout << "SuperSSN of employee: "; is >> employee.Superssn;
    cout << "Department Number of employee: "; is >> employee.Dno;
    return is;
}

istream& operator >> (istream& is, DepartmentLocations& departmentLocations) {
    cout << "Number of Department: "; is >> departmentLocations.Dnumber; is.ignore();
    cout << "Location of Department: "; getline(is, departmentLocations.Dlocation);
    return is;
}

istream& operator >> (istream& is, Department& department){
    //    Name of department
    cout << "Name of department: "; getline(is, department.Dname); 
    //    Number of department 
    cout << "Number of department: "; is >> department.Dnumber;
    //    Social security number of manager 
    cout << "Social security number of manager: "; is >> department.Mgrssn;
    //    Department management start date of manager
    is.ignore();
    cout << "Department management start date of manager: "; getline(is, department.Mgrstartdate);
    return is;
}
istream& operator >> (istream& is, Workson& worskon){
    //    Social security number of employee
    cout << "Social security number of employee: "; is >> worskon.Essn;
    //    Number of project 
    cout << "Number of project: "; is >> worskon.Pno;
    //    Overtime hours
    cout << "Overtime hours of employee: ";is >> worskon.Hours;
    //    Overtime hours
    return is;
}

istream& operator >> (istream& is, Dependent& dependent) {         
    cout << "Social security number of employee: "; is >> dependent.Essn;
    is.ignore(); 
    cout << "Name of dependent: "; getline(is, dependent.DependentName);
    cout << "Birthday of employee: "; getline(is, dependent.Bdate);
    cout << "Sex of employee: "; is >> dependent.Sex;
    is.ignore();  
    cout << "Realationship of dependent: "; getline(is, dependent.Relationship);
    return is;
}

istream& operator >> (istream& is, Project& project) {     
    cout << "Name of project: "; getline(is, project.Pname);
    cout << "Serial number of project: "; is >> project.Dnum;
    is.ignore();
    cout << "Location of project: "; getline(is, project.Plocation);
    cout << "Number of department doing project: "; is >> project.Pnumber;
    return is;
}