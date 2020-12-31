#include "UIMenu.h"
void UIMenu::Display(DataBusinessObject* databusinessobject) {
    for (int i = 0; i < databusinessobject->GetSize(); i++) {
        BusinessObject* businessobject = databusinessobject->GetPointer(i);
        cout << businessobject->GetID() << " " << businessobject->ToString() << endl << endl;
    }
}

void UIMenu::DisplayAllEmpUnderSupvr(string name) {
    int ssn;
    for (int i = 0; i < employeedata.GetSize(); i++) {
        if (name == employeedata.Get(i).GetName()) {
            ssn =  employeedata.Get(i).GetSsn();
            for (int j = 0; j < employeedata.GetSize(); j++) {
                if ( employeedata.Get(j).GetSuperssn() == ssn) {
                    cout << employeedata.Get(j).GetName() << endl;
                }
            }
        }
    }
}

void UIMenu::DisplayAllEmpHasChild() {
    for (int i = 0; i < dependentdata.GetSize(); i++) {
        if (dependentdata.Get(i).GetRelationship() == "DAUGHTER" || dependentdata.Get(i).GetRelationship() == "SON") {
            int ssn = dependentdata.Get(i).GetEssn();
            for (int j = 0; j < employeedata.GetSize(); j++) {
                if (employeedata.Get(j).GetSsn() == ssn) {
                    cout << employeedata.Get(j).GetName() << " have a " << dependentdata.Get(i).GetRelationship() << endl;
                }
            }
        }
    }
}

void UIMenu::DisplayAverageSalaryEmpInDepartment(string& departmentname) {
    int pnumber;
    for (int i = 0; i < departmentdata.GetSize(); i++) {
        if (departmentdata.Get(i).GetDName() == departmentname) {
            cout << "Average salary of employee in " << departmentname << ": ";
            pnumber = departmentdata.Get(i).GetDNumber();
            break;
        }
    }       
    double average = 0;
    int count = 0;
    for (int j = 0; j < employeedata.GetSize(); j++) {
        if (employeedata.Get(j).GetDno() == pnumber) {
            count++;
            average += employeedata.Get(j).GetSalary();
        }
    }
    average = average / count;
    cout << average;
}

void UIMenu::DisplayAllEmpInDepartment(int& departmentnumber, string& projectname, int& minhours) {
    int pnumber, essn;
    cout << "All Employee in department: " << departmentnumber << ", work at: " << projectname << ", min hours: " << minhours <<endl;
    for (int i = 0; i < projectdata.GetSize(); i++) {
        if (projectdata.Get(i).GetDnum() == departmentnumber && projectdata.Get(i).GetPname() == projectname) {
            pnumber = projectdata.Get(i).GetPnumber();
            break;
        }
    }
    cout << pnumber << endl;
    for (int j = 0; j < worksondata.GetSize(); j++) {
        if (worksondata.Get(j).GetPno() == pnumber && worksondata.Get(j).GetHours() > minhours) {
            essn = worksondata.Get(j).GetEssn();
            for (int k = 0; k < employeedata.GetSize(); k++) {
                if (employeedata.Get(k).GetSsn() == essn && employeedata.Get(k).GetDno() == departmentnumber) {
                    cout << employeedata.Get(k).GetName() << " ";
                }
            }
        }
    }
}

void UIMenu::DisplayAllEmpNoProject() {
    bool k = true;
    for (int i = 0; i < employeedata.GetSize(); i++) {
        for(int j = 0; j < worksondata.GetSize(); j++) {
            if (employeedata.Get(i).GetSsn() == worksondata.Get(j).GetEssn()) {
                k = false;
                break;
            }
        }
    if(k) cout << employeedata.Get(i).GetID() << " " << employeedata.Get(i).ToString() << endl;
    k = true;
    }
}

void UIMenu:: DisplayManaNoDependent() {
    bool k = true;
    for (int i = 0; i < departmentdata.GetSize(); i++) {
        for(int j=0; j< dependentdata.GetSize(); j++) {
            if(departmentdata.Get(i).GetMgrssn() == dependentdata.Get(j).GetEssn()) {
                k = false;
                break;
            }
        }
        if(k) {
            cout << "The last name of managers who haven't dependent people : " << endl;
            for(int l=0; l<employeedata.GetSize(); l++){
                if(departmentdata.Get(i).GetMgrssn() == employeedata.Get(l).GetSsn()) {
                    cout <<  employeedata.Get(l).GetName()<<endl;
                }
            }
        }
        k = true;
    }
}

void UIMenu::TotalWorkHours(int& n)
{
    double sum = 0;
    for (int i = 0; i < projectdata.GetSize(); i++) {
        if (projectdata.Get(i).GetPnumber() == n) {
            cout << "Name of Project: "<< projectdata.Get(i).GetPname() << ", Total work hours: ";
            break;
        }
    }
    for (int j = 0; j < worksondata.GetSize(); j++) {
        if (worksondata.Get(j).GetPno() == n) {
            sum += worksondata.Get(j).GetHours();
        }
    }
    if (sum != 0) {
        cout << sum;
    }
    else {
        cout << "There is no project as you type. Please try again"<<endl;
    }
}

void UIMenu::AverageIncomeBySex(char& s){
    if (s != 'M' && s != 'F'){
        cout << "Please type again"<<endl;
    }
    else{
        int count = 0;
        float TotalIncome = 0;
        for (int i=0; i < employeedata.GetSize(); i++){
            if (employeedata.Get(i).GetSex() == s){
                TotalIncome += employeedata.Get(i).GetSalary();
                count++;
            }
        }
        cout << "Average income by "<<s<<" is: "<< TotalIncome/count<<endl;
        cout << endl;
    }
}

void UIMenu::ChooseSentence() {
    cout << endl;
    do {
        cout << "                                      EMPLOYEE MANAGEMENT PROGRAM\n";
        cout << "**********************************************MENU*************************************************************\n";
        cout << "**  1.  Add/Eddit/Delete/Read management infomation.                                                         **\n";
        cout << "**  2.  Display the names of all employees being monitored.                                                  **\n";
        cout << "**  3.  Show all employee names that dependent is daughter or son.                                           **\n";
        cout << "**  4.  Display project name, total hours that all employees have to work for that project.                  **\n";
        cout << "**  5.  Display the names of all employees who are not part of any project.                                  **\n";
        cout << "**  6.  Display the department name and the average salary of the employees working for that department.     **\n";
        cout << "**  7.  Average salary of all employees by sex                                                               **\n";
        cout << "**  8.  last names of all managers of the department but not dependent.                                      **\n";
        cout << "**  9.  Displays the names of all employees in a department and work for a project with the minimum hours.   **\n";
        cout << "**  10. Built in features to backup and restore data.                                                        **\n";
        cout << "**  0.  Exit                                                                                                 **\n";
        cout << "***************************************************************************************************************\n";
        int k;
        cout << endl << "**  Enter your choose: ";
        cin >> k;
        switch(k) {
            case 1:
                ChooseTable();
                break;
            case 2:
                {
                    string name;
                    cout << "Enter name of supervisor: ";
                    cin >> name;
                    DisplayAllEmpUnderSupvr(name);
                }
                break;
            case 3:
                DisplayAllEmpHasChild();
                break;
            case 4:
                {
                    int pronum;
                        cout << "Enter project number: ";
                        cin >> pronum;
                        while (cin.fail()){
                            cin.clear();
                            cin.ignore();
                            cout <<"Not a valid number, please type again: ";
                            cin>>pronum;
                        }
                    TotalWorkHours(pronum);
                }
                break;
            case 5:
                DisplayAllEmpNoProject();
                break;
            case 6:
                {
                    string name;
                    cout << "Enter name of department: ";
                    cin >> name;
                    DisplayAverageSalaryEmpInDepartment(name);   
                }
                break;
            case 7:
                {
                    char s;
                    cout << "Enter the sex: 'M' or 'F' ";
                    cin >> s;
                    AverageIncomeBySex(s); 
                }
                break;
            case 8:
                DisplayManaNoDependent();
                break;
            case 9:
                {
                    int departmentnumber, minhours;
                    string projectname;
                    cout << "Enter department number: ";
                    cin >> departmentnumber;
                    cout << "Enter project name: ";
                    cin >> projectname;
                    cout << "Enter min hours: ";
                    cin >> minhours;
                    DisplayAllEmpInDepartment(departmentnumber, projectname, minhours);
                }
                break;
            case 10:
                {
                    employeedata.ExportToFile("EmployeeData.data");
                    departmentdata.ExportToFile("DepartmentData.Data");
                    dependentdata.ExportToFile("DependentData.data");
                    worksondata.ExportToFile("WorksonData.data");
                    projectdata.ExportToFile("ProjectData.data");
                    departmentlocationsdata.ExportToFile("DepartmentLocationsData.data");
                }
                break;
            case 0:
                exit('0');
            default:
                system("cls");
                cout << "Your choice is wrong, please try again: ";
                break;
            
        }
    } while(1);
}

void UIMenu::ChooseTable(){
    system("cls");
    bool k = true;
    do {
        cout << "MANAGEMENT INFORMATION\n";
        cout << "*************************MENU************************************\n";
        cout << "**  1. Infomation of employees.                                **\n";
        cout << "**  2. Infomation of departments.                              **\n";
        cout << "**  3. Location of departments.                                **\n";
        cout << "**  4. Infomation of projects.                                 **\n";
        cout << "**  5. Overtime information of employees.                      **\n";  
        cout << "**  6. Information of Employee has dependent.                  **\n";
        cout << "**  7. Return to previous menu.                                **\n";
        cout << "**  0. Exit.                                                   **\n";
        cout << "*****************************************************************\n";
        int n ;
        cout << "Your selection : " ; 
        cin >> n; // To choose the information that you need
        switch(n){
            case 1:
                ChooseOpt(n);
                break;
            case 2:
                ChooseOpt(n);
                break;
            case 3:
                ChooseOpt(n);
                break;        
            case 4:
                ChooseOpt(n);
                break;    
            case 5:
                ChooseOpt(n);
                break;
            case 6:
                ChooseOpt(n);
                break;
            case 7:
                k = false;
                break;
            case 0:
                exit('0');
            default:
                system("cls");
                cout << "Your choice is wrong, please try again: ";
                break;
        }
    } while(k);
}
void UIMenu::ChooseOpt(int n)
{
    system("cls");
    bool k = true;
    do {
        cout <<"              EMPLOYEE MANAGEMENT PROGRAM\n";
        cout <<"*************************MENU*****************************\n";
        cout <<"**  1. Add information.                                 **\n";
        cout <<"**  2. Edit information.                                **\n";
        cout <<"**  3. Delete information.                              **\n";
        cout <<"**  4. Read information.                                **\n";
        cout <<"**  5. Return to previous menu.                         **\n";
        cout <<"**  0. Exit.                                            **\n";
        cout <<"**********************************************************\n";
        int x;
        cout <<"Press a number :";
        cin>>x;
        switch (x) { 
            case 1:
                if (n == 1) {
                    Employee employee;
                    cin >> employee;
                    employeedata.Add(employee);
                    Display(&employeedata);  
                }
                else if (n == 2) {
                    Department department;
                    cin >> department;
                    departmentdata.Add(department);
                    Display(&departmentdata);
                }
                else if (n == 3) {
                    DepartmentLocations departmentlocation;
                    cin >> departmentlocation;
                    departmentlocationsdata.Add(departmentlocation);
                    Display(&departmentlocationsdata);
                }
                else if (n == 4) {
                    Project project;
                    cin >> project;
                    projectdata.Add(project);
                    Display(&projectdata);
                }
                else if (n == 5) {
                    Workson workson;
                    cin >> workson;
                    worksondata.Add(workson);
                    Display(&worksondata);
                }
                else if (n == 6) {
                    Dependent dependent;
                    cin >> dependent;
                    dependentdata.Add(dependent);
                    Display(&dependentdata);
                }
                break;
            case 2:
                if (n == 1) {
                    int id;
                    cout << "Enter the person who you want to edit: ";
                    cin >> id;
                    cout << "Edit the person who you want to edit: "<<endl;
                    Employee employee;
                    cin >> employee;
                    employeedata.Edit(employee,id - 1);    
                    Display(&employeedata);  
                
                }
                else if (n == 2) {
                    int id;
                    cout << "Enter the person who you want to edit: ";
                    cin >> id;
                    cout << "Edit the person who you want to edit: "<<endl;
                    Department department;
                    cin >> department;                    
                    departmentdata.Edit(department,id - 1);    
                    Display(&departmentdata);
                }
                else if (n == 3) {
                    int id;
                    cout << "Enter the person who you want to edit: ";
                    cin >> id;
                    cout << "Edit the person who you want to edit: "<<endl;
                    DepartmentLocations departmentlocation;
                    cin >> departmentlocation;
                    departmentlocationsdata.Edit(departmentlocation,id - 1);    
                    Display(&departmentlocationsdata);  
                } 
                else if (n == 4) {
                    int id;
                    cout << "Enter the person who you want to edit: ";
                    cin >> id;
                    cout << "Edit the person who you want to edit: "<<endl;
                    Project project;
                    cin >> project;
                    projectdata.Edit(project,id - 1);    
                    Display(&projectdata);  
                }
                else if (n == 5) {
                    int id;
                    cout << "Enter the person who you want to edit: ";
                    cin >> id;
                    cout << "Edit the person who you want to edit: "<<endl;
                    Workson workson;
                    cin >> workson;
                    worksondata.Edit(workson,id - 1);     
                    Display(&worksondata);
                }
                else if (n == 6) {
                    int id;
                    cout << "Enter the person who you want to edit: ";
                    cin >> id;
                    cout << "Edit the person who you want to edit: " <<endl;
                    Dependent dependent;
                    cin >> dependent;
                    dependentdata.Edit(dependent,id - 1);     
                    Display(&dependentdata);
                }
                break;
            case 3:
                if (n == 1) {
                    int id;
                    cout << "Enter the person who you want to delete: ";
                    cin >> id;
                    employeedata.Delete(id);
                    Display(&employeedata);
                
                }
                else if (n == 2) {
                    int id;
                    cout << "Enter the person who you want to delete: ";
                    cin >> id;
                    departmentdata.Delete(id);
                    Display(&departmentdata);
                
                }
                else if (n == 3) {
                    int id;
                    cout << "Enter the person who you want to delete: ";
                    cin >> id;
                    departmentlocationsdata.Delete(id);
                    Display(&departmentlocationsdata);
                
                }
                else if (n == 4) {
                    int id;
                    cout << "Enter the person who you want to delete: ";
                    cin >> id;
                    projectdata.Delete(id);
                    Display(&projectdata);
                
                }
                else if (n == 5) {
                    int id;
                    cout << "Enter the person who you want to delete: ";
                    cin >> id;
                    worksondata.Delete(id);
                    Display(&worksondata);
                }
                else if (n == 6) {
                    int id;
                    cout << "Enter the person who you want to delete: ";
                    cin >> id;
                    dependentdata.Delete(id);
                    Display(&dependentdata);
                }
                break;
            case 4:
                if (n == 1) {
                    employeedata.Read("Data/EmployeeData.data");
                    Display(&employeedata);
                }
                if (n == 2) {
                    departmentdata.Read("Data/DepartmentData.data");
                    Display(&departmentdata);
                }
                else if (n == 3) {
                    departmentlocationsdata.Read("Data/DepartmentLocationsData.data");
                    Display(&departmentlocationsdata);
                }
                else if (n == 4) {
                    projectdata.Read("Data/ProjectData.data");
                    Display(&projectdata);                
                }
                else if (n == 5) {
                    worksondata.Read("Data/WorksonData.data");
                    Display(&worksondata);
                }
                else if (n == 6) {
                    dependentdata.Read("Data/DependentData.data");
                    Display(&dependentdata);
                }
                break;
            case 5:
                k = false;
                break;
            case 0:
                exit('0');
            default:
                system("cls");
                cout << "Your choice is wrong, please try again: ";
                break;
        } 
    } while(k);
}