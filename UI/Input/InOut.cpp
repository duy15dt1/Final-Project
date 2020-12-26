#include "InOut.h"
// Overloading extraction operator 

istream& operator >> (istream& is, Employee& emp) {   
    is.ignore();       
    cout << "First name of employee "; getline(is, emp.Fname);
    cout << "Middle nane of employee "; is >> emp.Minit; is.ignore();
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

istream& operator >> (istream& is, Dept_locations& dept) {
    cout << "Number of Department: "; is >> dept.Dnumber; is.ignore();
    cout << "Location of Department: "; getline(is, dept.Dlocation);
    return is;
}

istream& operator >> (istream& is, Department& depa){
    is.ignore();
    //    Name of department
    cout << "Name of department "; getline(is, depa.Dname); 
    //    Number of department 
    cout << "Number of department "; is >> depa.Dnumber;
    //    Social security number of manager 
    cout << "Social security number of manager "; is >> depa.Mgrssn;
    //    Department management start date of manager
    is.ignore();
    cout << "Department management start date of manager "; getline(is, depa.Mgrstartdate);
    return is;
}
istream& operator >> (istream& is, Work_on& workon){
    //    Social security number of employee
    cout << "Social security number of employee "; is >> workon.Essn;
    //    Number of project 
    cout << "Number of project "; is >> workon.Pno;
    //    Overtime hours
    cout << "Overtime hours of employee ";is >> workon.Hours;
    //    Overtime hours
    return is;
}

istream& operator >> (istream& is, Dependent& dep) {         
    cout << "Social security number of employee "; is >> dep.Essn;
    is.ignore(); 
    cout << "Name of dependent "; getline(is, dep.Dependent_name);
    is.ignore();  
    cout << "Birthday of employee "; getline(is, dep.Bdate);
    cout << "Sex of employee "; is >> dep.Sex;
    is.ignore();  
    cout << "Realationship of dependent "; getline(is, dep.Relationship);
    return is;
}

istream& operator >> (istream& is, Project& pro) {   
    is.ignore();       
    cout << "Name of project "; getline(is, pro.Pname);
    cout << "Serial number of project"; is >> pro.Dnum;
    cout << "Location of project "; getline(is, pro.Plocation);
    cout << "Number of department doing project "; is >> pro.Pnumber;
    return is;
}