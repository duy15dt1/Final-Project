#include "ChooseOpt.h"
void ChooseOpt(int n)
{
    cout <<"              EMPLOYEE MANAGEMENT PROGRAM\n";
    cout <<"*************************MENU**************************\n";
    cout <<"**1. Add information                              = 1**\n";
    cout <<"**2. Edit information                             = 2**\n";
    cout <<"**3. Delete information                           = 3**\n";
    cout <<"**4. Read information                             = 4**\n";
    cout <<"**0. Exit                                         = 0**\n";
    cout <<".......................................................\n";
    int x;
    cout <<"Press a number :";
    cin>>x;
    switch (x){ 
        case 1:
            if (n == 1) {
                Employee emp;
                cin >> emp;
                empArr.push_back(emp);
            }
            else if (n == 2) {
                Department depart;
                cin >> depart;
                departArr.push_back(depart);
            }
            else if (n == 3) {
                Dept_locations dept;
                cin >> dept;
                deptArr.push_back(dept);
            }
            else if (n == 4) {
                Project p;
                cin >> p;
                pArr.push_back(p);
            }
            else if (n == 5) {
                Work_on w;
                cin >> w;
                wArr.push_back(w);
            }
            else {
                Dependent depe;
                cin >> depe;
                depeArr.push_back(depe);
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            if (n == 1) {
                for (int i = 0; i < departArr.size(); i++) {
                    cout << departArr[i];
                }
            }
            else if (n == 2) {
                for (int i = 0; i < empArr.size(); i++) {
                    cout << empArr[i];
                }
            }
            else if (n == 3) {
                for (int i = 0; i < deptArr.size(); i++) {
                    cout << deptArr[i];
                }
            }
            else if (n == 4) {
                for (int i = 0; i < pArr.size(); i++) {
                    cout << pArr[i];
                }
            }
            else if (n == 5) {
                for (int i = 0; i < wArr.size(); i++) {
                    cout << wArr[i];
                }
            }
            else {
                for (int i = 0; i < depeArr.size(); i++) {
                    cout << depeArr[i];
                }
            }
            break;
        case 0:
            break;
    } 
}