#include "Employee.h"

Employee::Employee() {
}

//The this pointer is an implicit parameter to all member functions
//Therefore, inside a member function, this may be used to refer to the invoking object
Employee::Employee(string Fname, string Minit, string Lname, int Ssn, string Bdate, string Address, char Sex, int Salary, int Superssn, int Dno) {
    this->Fname = Fname;
    this->Minit = Minit;
    this->Lname = Lname;
    this->Ssn = Ssn;
    this->Bdate = Bdate;
    this->Address = Address;
    this->Sex = Sex;
    this->Salary = Salary;
    this->Superssn = Superssn;
    this->Dno = Dno;
}
string Employee::GetName() {
    return Fname + " " + Lname;
}
string Employee::GetFname() {
    return Fname;
}
string Employee::GetMinit() {
    return Minit;
}
string Employee::GetLname() {
    return Lname;
}
int Employee::GetSsn() {
    return Ssn;
}
string Employee::GetBdate() {
    return Bdate;
}
string Employee::GetAddress() {
    return Address;
}
char Employee::GetSex() {
    return Sex;
}
int Employee::GetSalary() {
    return Salary;
}
int Employee::GetSuperssn() {
    return Superssn;
}
int Employee::GetDno() {
    return Dno;
}
int& Employee::GetIDMax() {
    return sIDMax;
}

void Employee::IncreaseID() {
    ID = ++sIDMax;
}

/** Sex is char so we have to use "to_string"
 *  in library "string" to convert so that we can display
 *  DO NOT REMOVE "to_string" or it can get issues
 *  @return a string
 *  Example: 
 *  {Fname: John, Minit: B, Lname: Smith, Ssn: 123456789, Bdate: 1965-01-09, Address: 731 Fondren, Houston, TX, Sex: N, Salary: 30000, Superssn: 333445555, Dno: 5}
 */
string Employee::ToString() {
    string s;
    s += "{Fname: " + Fname + ", ";
    s += "MInit:" + Minit + ", ";
    s += "Lname: " + Lname + ", ";
    s += "SSN: " + to_string(Ssn) + ", ";
    s += "BDate: " + Bdate + ", ";
    s += "Adrress: " + Address + ", ";
    string str = string(1, Sex);
    s += "Sex: " + str + ", ";
    s += "Salary: " + to_string(Salary) + ", ";
    s += "SuperSSN: " + to_string(Superssn) + ", ";
    s += "DNO: " + to_string(Dno) + "}";
    return s;
}

string Employee::PrintElement() {
    string s;
    s += "Fname: " + Fname + ", ";
    s += "MInit:" + Minit + ", ";
    s += "Lname: " + Lname + ", ";
    s += "SSN: " + to_string(Ssn) + ", ";
    s += "BDate: " + Bdate + ", ";
    s += "Adrress: " + Address + ", ";
    string str = string(1, Sex);
    s += "Sex: " + str + ", ";
    s += "Salary: " + to_string(Salary) + ", ";
    if (Superssn == 0) {
        s += "SuperSSN: null, ";
    }
    else {
        s += "SuperSSN: " + to_string(Superssn) + ", ";
    }
    s += "DNO: " + to_string(Dno) + "";
    return s;
}

/** @brief Function converts this object to json object.
 *  
 *  Function converts this object to json object.
 *  @return a json object;
 *  Example: 
 *  {"Fname":"John","Minit":"B","Lname":"Smith","Ssn":123456789,"Bdate":"1965-01-09","Address":"731Fondren, Houston, TX","Sex":"M","Salary":30000,"Superssn":333445555,"Dno":5}
 */
json Employee::ToJson() {
    json j;
    j["Minit"] = Minit;
    j["Lname"] = Lname;
    j["Ssn"] = Ssn;
    j["Bdate"] = Bdate;
    j["Address"] = Address;
    j["Fname"] = Fname;
    j["Sex"] = string(1, Sex);
    j["Salary"] = Salary;
    j["Superssn"] = Superssn;
    j["Dno"] = Dno;
    return j;
}

//sIdMax is a static variable so we have to set it to 0 every time we want to use it
//to avoid unexpected issues
int Employee::sIDMax = 0;