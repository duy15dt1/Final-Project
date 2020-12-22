#include "InOut.h"
// Overloading extraction operator 
istream& operator >> (istream& is, Department& d) {
    cout << "Name of department "; is.ignore(); getline(is, d.Dname);                                   //    Name of department
    cout << "Number of department "; is >> d.Dnumber;                                                   //    Number of department 
    cout << "Social security number of manager "; is >> d.Mgrssn;                                       //    Social security number of manager 
    cout << "Department management start date of manager "; is.ignore(); getline(is, d.Mgrstartdate);   //    Department management start date of manager
    return is;
}
istream& operator >> (istream& is, Dependent& de) {
    cout << "Social security number of employee "; is >> de.Essn;
    cout << "Name of dependent "; is >> de.Dependent_name;
    cout << "Sex of dependent "; is >> de.Sex;
    cout << "Date of birth of employee "; is >> de.Bdate;
    cout << "Relationship of dependent "; is >> de.Relationship;
    return is;
}
istream& operator >> (istream& is, Dept_locations& d) {
    cout << "Number of department: "; is >> d.Dnumber;
    cout << "Location of department: "; is >> d.Dlocation;
    return is;
}

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
    emp.Id++;
    return is;
}
istream& operator >> (istream& is, Project& p){
    cout << "Name of the project "; is >> p.Pname;
    cout << "Serial number of project "; is >> p.Pnumber;
    cout << "Location of project "; is >> p.Plocation;
    cout <<"Number of department"; is >> p.Dnum;
    return is;
}
istream& operator >> (istream& is, Work_on& w){
    cout << "Social security number of employee "; is >> w.Essn;//    Social security number of employee
    cout << "Number of project "; is >> w.Pno;                  //    Number of project 
    cout << "Overtime hours "; is >> w.Hours;                   //    Overtime hours 
    return is;
}
// Overloading insertion operator 
ostream& operator << (ostream& os, Department& d){
    os << d.Dname << " " << d.Dnumber << " " << d.Mgrssn << " " << d.Mgrstartdate << endl << endl;//    Department management start date of manager
    return os;
}
ostream& operator << (ostream& os, Dependent& de){
    os << de.Essn << " " << de.Dependent_name << " " << de.Sex << " " << de.Bdate << " " << de.Relationship << endl << endl;
    return os;
}
ostream& operator << (ostream& os, Dept_locations& d){
    os << d.Dnumber << endl << " " << d.Dlocation << endl << endl;
    return os;
}
ostream& operator << (ostream& os, Employee& emp){
    os << emp.Fname << " " << emp.Minit << " " << emp.Lname << " " << emp.Ssn << " " << emp.Bdate << " " << emp.Address << " " << emp.Sex << " " << emp.Salary << " " << emp.Superssn << " " << emp.Dno << " " << emp.Id << endl;
    cout << endl;
    return os;
}
ostream& operator << (ostream& os, Project& p){
    os << p.Pname << " " << p.Pnumber << " " << p.Plocation << " " << p.Dnum << endl << endl;
    return os;
}
ostream& operator << (ostream& os, Work_on& w){
    os << w.Essn << " " << w.Pno << " " << w.Hours << endl << endl;                   //    Overtime hours 
    return os;
}