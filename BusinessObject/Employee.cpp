#include "Employee.h"

Employee::Employee() {}

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

int Employee::GetSuperssn() {
    return Superssn;
}

int Employee::GetSsn() {
    return Ssn;
}

int Employee::GetDno() {
    return Dno;
}

int Employee::GetSalary() {
    return Salary;
}

char Employee::GetSex() {
    return Sex;
}


int& Employee::GetId() {
    return Id;
}

int& Employee::GetIdNew() {
    return Idnew;
}

void Employee::IncreaseId() {
    Id = ++Idnew;
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

/** @brief Function converts this object to json object.
 *  
 *  Function converts this object to json object.
 *  @return a json object;
 *  Example: 
 *  {"Fname":"John","Minit":"B","Lname":"Smith","Ssn":123456789,"Bdate":"1965-01-09","Address":"731Fondren, Houston, TX","Sex":"M","Salary":30000,"Superssn":333445555,"Dno":5}
 */
json Employee::ToJson(){
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

int Employee::Idnew = 0;