#include "UI_Choose.h"
void UI_Choose::DisplayEmployees(EmployeeData& employeeData) {
    for (int i = 0; i < employeeData.GetSize(); i++) {
        Employee e = employeeData.Get(i);
        cout << e.GetId() << " " << e.ToString() << endl << endl;
    }
}

void UI_Choose::Choose_sentence() {
    cout << endl;
    do {
        cout << "                                      EMPLOYEE MANAGEMENT PROGRAM\n";
        cout << "**********************************************MENU*************************************************************\n";
        cout << "**  1. Add/Eddit/Delete/Read management infomation.                                                          **\n";
        cout << "**  2. Displays the names of all employees being monitored.                                                  **\n";
        cout << "**  3. Show all employee names that dependent is daughter or son.                                            **\n";
        cout << "**  4. Displays project name, total hours that all employees have to work for that project.                  **\n";
        cout << "**  5. the names of all employees who are not part of any project.                                           **\n";
        cout << "**  6. Display the department name and the average salary of the employees working for that department.      **\n";
        cout << "**  7. Average salary of all employees by sex                                                                **\n";
        cout << "**  8. last names of all managers of the department but not dependent.                                       **\n";
        cout << "**  9. Displays the names of all employees in a department and work for a project with the minimum hours.    **\n";
        cout << "**  10. Built in features to backup and restore data.                                                        **\n";
        cout << "**  0. Exit                                                                                                  **\n";
        cout << "***************************************************************************************************************\n";
        int k;
        cout << endl << "**  Enter your choose: ";
        cin >> k;
        switch(k) {
            case 1:
                ChooseTable();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
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

void UI_Choose::ChooseTable(){
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
void UI_Choose::ChooseOpt(int n)
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
        switch (x){ 
            case 1:
                if (n == 1) {
                    employeedata.Add();
                    DisplayEmployees(employeedata);  
                }
                break;
            case 2:
                if (n == 1) {
                    int id;
                    cout << "Enter the person who idou want to edit: ";
                    cin >> id;
                    employeedata.Edit(id - 1);    
                    DisplayEmployees(employeedata);  
                
                }
                break;
            case 3:
                if (n == 1) {
                    int id;
                    cout << "Enter the person who yoid want to delete: ";
                    cin >> id;
                    employeedata.Delete(id);
                    DisplayEmployees(employeedata);
                
                }
                break;
            case 4:
                if (n == 1) {
                    employeedata.Read("EmployeeData.data");
                    DisplayEmployees(employeedata);
                }
                break;
            case 5:
                employeedata.ExportToFile("EmployeeData.data");
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