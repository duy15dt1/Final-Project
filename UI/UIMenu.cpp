#include "UIMenu.h"
#include <iomanip>

/** @brief Function describes the ability to display data
 *  
 *  Function describes the ability to display data.
 *  The function as the parameter passed is the pointer variable DataBusinessObject
 *  After looping through each element, it displays the PrintElement() of that element
 *  Example: ID: 1, "Essn":123456789,"Pno":1,"Hours":32.5
 */
void UIMenu::Display(DataBusinessObject* databusinessobject) {
    cout << endl;
    for (int i = 0; i < databusinessobject->GetSize(); i++) {
        BusinessObject* businessobject = databusinessobject->GetPointer(i);
        cout << "ID: " << businessobject->GetID() << ", " << businessobject->PrintElement() << endl ;
    }
    cout << endl << endl;
}

/** @brief The function shows all employees supervised by the person entered from the keyboard
 * function as the parameter is the string variable
 * After looping through each element at class EmployeeData, we get ssn variable
 * we check, if ssn = -1 return There is no name you typed, please type again
 * else after looting through each element at class EmployeeData, we get name of all employees supervised
 */
void UIMenu::DisplayAllEmpUnderSupvr(string name) {
    int ssn = -1;
    cout << "List of employees supervised by " << name << ": " << endl;
    for (int i = 0; i < employeedata.GetSize(); i++) {
        if (name == employeedata.Get(i).GetName()) {
            ssn = employeedata.Get(i).GetSsn();
            break;
        }
    }
    if (ssn == -1) {
        cout << "There is no name you typed, please type again";
    } else {
        int temp = 0;
        for (int j = 0; j < employeedata.GetSize(); j++) {
            if ( employeedata.Get(j).GetSuperssn() == ssn) {
                cout << employeedata.Get(j).GetName() << endl;
                temp = 1;
            }
        }
        if (temp == 0) {
            cout << "The employee you enter does not supervise anyone";
        }
    }
    cout << endl << endl;
}

/** @brief Function display all employee has dependent
 * @return name of employee has daughter or son
 * using a for loop in class Dependent to locate the employee by Essn
 * using another fo loop in class Employee
 * if the ssn in class Dependent similar to the essn in class Employee
 * then print the name of that employee who has a daughter or son
*/
void UIMenu::DisplayAllEmpHasChild() {
    int ssn = 0;
    cout << "List of employees that dependent is daughter or son: " << endl;
    for (int i = 0; i < dependentdata.GetSize(); i++) {
        if (dependentdata.Get(i).GetRelationship() == "DAUGHTER" || dependentdata.Get(i).GetRelationship() == "SON") {
            ssn = dependentdata.Get(i).GetEssn();
            for (int j = 0; j < employeedata.GetSize(); j++) {
                if (employeedata.Get(j).GetSsn() == ssn) {
                    cout << employeedata.Get(j).GetName() << " has a " << dependentdata.Get(i).GetRelationship() << endl;
                }
            }
        }
    }
    if (ssn == 0) {
        cout << "No employee that dependent is daughter or son";
    }
    cout << endl << endl;
}

/** @brief Function calculate the total work hours of all employee in a project.
 *  user will enter the project number.
 *  @return the total work hours
 *  sum is the variable to contain the total work hours.
 *  projectdata.GetSize() return the number of member in the class Project.
 *  Using the for loop in class Project to locate the project number which coincide to the number we entered.
 *  If the project number is the same then display name of that project.
 *  Using the second for loop in class Works_on to sum the project hours.
 *  If the project number matches nothing, ask the user to try again.
*/
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
        cout << "There is no project as you type. Please try again."<<endl;
    }
    cout << endl << endl;
}

/** @brief Function display all employee don't take part in project.
 *  Take employee's SSN in employee sheet to compare with employee's SSN of Wokson sheet.
 *  If not found, display employee information.
 *  @return no return
 *  Example a employee's SSN is 111111111, but it's not in work sheet. 
 *  So the function will display information of employee has 111111111 SSN
 */
void UIMenu::DisplayAllEmpNoProject() {
    bool k = true;
    cout << "List of employees who are not working on any project :" << endl;
    for (int i = 0; i < employeedata.GetSize(); i++) {
        for(int j = 0; j < worksondata.GetSize(); j++) {
            if (employeedata.Get(i).GetSsn() == worksondata.Get(j).GetEssn()) {
                k = false;
                break;
            }
        }
    if(k) cout << employeedata.Get(i).GetID() << " " << employeedata.Get(i).PrintElement() << endl;
    k = true;
    }
    cout << endl;
}

/** @brief Function display average salary of all employees in department
 * Function display average salary of all employees in department
 * Function as the parameter is string variable
 * After loop through each element at class DepartmentData, we get pnumber variable
 * We check, if pnumber = 0, return there is no department you typed, please type again.
 * else we loop through each element at class EmployeeData, we get average variable
*/
void UIMenu::DisplayAverageSalaryEmpInDepartment(string& departmentname) {
    int pnumber = 0;
    for (int i = 0; i < departmentdata.GetSize(); i++) {
        if (departmentdata.Get(i).GetDName() == departmentname) {
            cout << "Average salary of employee in " << departmentname << ": ";
            pnumber = departmentdata.Get(i).GetDNumber();
            break;
        }
    }
    if (pnumber == 0) {
        cout << "There is no department you typed, please type again.";
    } else {
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
    cout << endl << endl;
}

/** @brief fucntion calculate the average income of employee by sex
 *  user will enter the sex
 *  @return average income corerresponding with the sex
 *  variable count contain the number of male of female
 *  Using a for loop in class Employee locate the sex coincide to the sex we entered
 *  if the sex is the same then increase the count by 1 then add the Salary of that employee
*/
void UIMenu::AverageIncomeBySex(char& s){
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

/** @brief Function display the last name of all manager don't have dependent.
 *  Take manager's SSN in department sheet to compare with employee's SSN of dependent sheet.
 *  If not found, get the last name of manager in employee sheet then display it.
 *  @return no return
 *  Example a manager's SSN is 888665555, but it's not in dependent sheet. 
 *  So the function will get the last name of 888665555 in employee sheet (Borg) and display it.
 */
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
            cout << "The last name of managers who doesn't have dependent : " << endl;
            for(int l=0; l<employeedata.GetSize(); l++){
                if(departmentdata.Get(i).GetMgrssn() == employeedata.Get(l).GetSsn()) {
                    cout << employeedata.Get(l).GetLname() << endl;
                }
            }
        }
        k = true;
    }
    cout << endl;
}

/** @brief function display all employee in department, project and min hours entered form the keyboard
 * function display all employee in department, project and min hours entered form the keyboard
 * Function as the parameter is two int variable and string variable
 * After loop through each element at class ProjectData, we get pnumber variable
 * After loop through each element at class WorksonData and EmployeeData, we return name all employee
*/
void UIMenu::DisplayAllEmpInDepartment(int& departmentnumber, string& projectname, int& minhours) {
    int pnumber = 0, essn = 0;
    for (int i = 0; i < projectdata.GetSize(); i++) {
        if (projectdata.Get(i).GetDnum() == departmentnumber && projectdata.Get(i).GetPname() == projectname) {
            pnumber = projectdata.Get(i).GetPnumber();
            break;
        }
    }
    if (pnumber == 0) {
        cout << "No project you typed, please type again" << endl;
    }
    else {
        cout << "All Employee in department: " << departmentnumber << ", work at: " << projectname << ", min hours: " << minhours <<endl;
        for (int j = 0; j < worksondata.GetSize(); j++) {
            if (worksondata.Get(j).GetPno() == pnumber && worksondata.Get(j).GetHours() > minhours) {
                essn = worksondata.Get(j).GetEssn();
                for (int k = 0; k < employeedata.GetSize(); k++) {
                    if (employeedata.Get(k).GetSsn() == essn && employeedata.Get(k).GetDno() == departmentnumber) {
                        cout << employeedata.Get(k).GetName() << endl;
                    }
                }
            }
        }
        if (essn == 0) {
            cout << "No one in department:" << departmentnumber << ", work at: " << projectname << ", min hours: " << minhours <<endl;
        }
    }
    cout << endl;
}

/** @brief Function save the file datas of work.
 *  Save datas into "BackUpData/foldername" path with foldername is string entered from keyboard by user.
 *  New folder will be created in BackUpData folder.
 *  Then ExportToFile method will be called and export the file datas into new folder.
 *  @return no return
 *  Example  Enter the foldername is "30/04/1975" then new folder is created in BackUpData and data will be saved into it.
 */
void UIMenu::SaveFile(string& foldername) {
    const char* pathname = ("BackUpData/" + foldername).c_str();
    mkdir(pathname);
    employeedata.ExportToFile("BackUpData/" + foldername + "/EmployeeData.data");
    departmentdata.ExportToFile("BackUpData/" + foldername + "/DepartmentData.Data");
    dependentdata.ExportToFile("BackUpData/" + foldername + "/DependentData.data");
    worksondata.ExportToFile("BackUpData/" + foldername + "/WorksonData.data");
    projectdata.ExportToFile("BackUpData/" + foldername + "/ProjectData.data");
    departmentlocationsdata.ExportToFile("BackUpData/" + foldername + "/DepartmentLocationsData.data");
}

/** @brief Function get the saved folder name .
 *  Get the name folder in "BackUpData/BackUpName.txt" and save them in a string vector.
 *  @return string vector 
 */
vector<string> UIMenu::GetNameBackUpFile() {
    ifstream backupname("BackUpData/BackUpName.txt");
    vector<string> backupnamearr;
    string temp;
    while(getline(backupname,temp)) {
        backupnamearr.push_back(temp);
    }
    backupname.close();
    return backupnamearr;
}

/** @brief Function restore the file datas from folder saved.
 *  Restore datas from "BackUpData/foldername" path with foldername is string entered from keyboard by user.
 *  If there isn't foldername, function will not read anything.
 *  @return no return
 */
void UIMenu::BackUpFile(string& foldername) {
    employeedata.Read("BackUpData/" + foldername + "/EmployeeData.data");
    departmentdata.Read("BackUpData/" + foldername + "/DepartmentData.Data");
    dependentdata.Read("BackUpData/" + foldername + "/DependentData.data");
    worksondata.Read("BackUpData/" + foldername + "/WorksonData.data");
    projectdata.Read("BackUpData/" + foldername + "/ProjectData.data");
    departmentlocationsdata.Read("BackUpData/" + foldername + "/DepartmentLocationsData.data");

}

void UIMenu::ChooseSentence() {
    system("cls");
    do {
        cout << endl << endl << endl;
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
        cout << "**  10. Built in features to store data.                                                                     **\n";
        cout << "**  11. Built in features to restore data.                                                                   **\n";
        cout << "**  0.  Exit                                                                                                 **\n";
        cout << "***************************************************************************************************************\n";
        int k;
        cout << endl << "**  Enter your choose: ";
        cin >> k;
        cin.ignore();
        switch(k) {
            case 1:
                ChooseTable();
                break;
            case 2:
                {
                    string name;
                    cout << "Enter name of supervisor: ";
                    getline(cin,name);
                    DisplayAllEmpUnderSupvr(name);
                }
                break;
            case 3:
                DisplayAllEmpHasChild();
                break;
            case 4:
                {
                    int pronum;
                    do{
                        if(cin.fail()){
                            cout <<"Error"<<endl;
                            cin.clear();
                            cin.ignore();
                        }
                        cout<<"Enter number: ";
                        cin>>pronum;
                    } while(cin.fail());
                    TotalWorkHours(pronum);
                    break; 
                }
                break;
            case 5:
                DisplayAllEmpNoProject();
                break;
            case 6:
                {
                    string name;
                    cout << "Enter name of department: ";
                    getline(cin,name);
                    DisplayAverageSalaryEmpInDepartment(name);   
                }
                break;
            case 7:
                {
                    char s;
                    do{
                        if (s != 'M' && s != 'F'){
                            cout << "Please type again."<<endl;
                        }
                        cout << "Enter the sex: 'M' or 'F': ";
                        cin >> s;
                    }while(s != 'M' && s != 'F');
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
                    cout << "Enter project name: ";
                    getline(cin, projectname); 
                    do{
                        if(cin.fail()){
                            cout <<"Error"<<endl;
                            cin.clear();
                            cin.ignore();
                        }
                        cout << "Enter department number: ";
                        cin >> departmentnumber;
                    } while(cin.fail());
                    do{
                        if(cin.fail()){
                            cout <<"Error"<<endl;
                            cin.clear();
                            cin.ignore();
                        }
                        cout << "Enter min hours: ";
                        cin >> minhours;
                    } while(cin.fail());
                    DisplayAllEmpInDepartment(departmentnumber, projectname, minhours);
                }
                break;
            case 10:
                {
                    string foldername;
                    cout << "Enter name of folder you want to save: ";
                    getline(cin,foldername);
                    SaveFile(foldername);
                    bool check = true;
                    vector<string> backupnamearr = GetNameBackUpFile();
                    for (string temp:backupnamearr) {
                        if (foldername == temp) {
                            check = false;
                            break;
                        }
                    }
                    if (check) {
                    ofstream backupnamefile("BackUpData/BackUpName.txt",ios::app);
                    backupnamefile << foldername << endl;
                    backupnamefile.close();
                    }
                }
                break;
            case 11:
                {   
                    vector<string> backupnamearr = GetNameBackUpFile();
                    for (int i = 0; i < backupnamearr.size(); i++) {
                        cout << i << " " << backupnamearr[i] << endl;
                    }
                    cout << "Enter ordinal number folder you want to take: ";
                    int i;
                    cin >> i; cin.ignore();
                    BackUpFile(backupnamearr[i]);
                    Display(&employeedata);
                    Display(&departmentdata);
                    Display(&projectdata);
                    Display(&dependentdata);
                    Display(&worksondata);
                    Display(&departmentlocationsdata);

                }

                break;
            case 0:
                exit('0');
            default:
                system("cls");
                cout << "Your choice is wrong, please try again: ";
                break;
            
        }
        if (k != 0) {
            system("pause");
            system("cls");
        }
    } while(1);
}

void UIMenu::ChooseTable(){
    system("cls");
    cout << endl << endl << endl;
    bool k = true;
    do {
        system("cls");
        cout << endl << endl << endl;
        cout << "                    MANAGEMENT INFORMATION\n";
        cout << "*****************************MENU********************************\n";
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
        cout << "Your selection: " ; 
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
                ChooseSentence();
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
        cout << endl << endl << endl;
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
        cout <<"Press a number: ";
        cin >> x;
        cin.ignore();
        switch (x) { 
            case 1:
                if (n == 1) {
                    Employee employee;
                    cin >> employee;
                    employeedata.Add(employee);
                    cout << endl;
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
                    cin.ignore();
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
                    cin.ignore();
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
                    cin.ignore();
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
                    cin.ignore();
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
                    cin.ignore();
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
                    cin.ignore();
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
        if (k != 0 && k != 5) {
            system("pause");
            system("cls");
        } 
    } while(k);
}