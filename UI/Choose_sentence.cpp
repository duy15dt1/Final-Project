#include "Choose_sentence.h"
void Choose_sentence() {
    cout << endl << endl;
    cout << "EMPLOYEE MANAGEMENT PROGRAM\n";
        cout << "*************************MENU**********************************************************************************\n";
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
            default:
                break;
            
        }
}