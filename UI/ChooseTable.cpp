#include "ChooseTable.h"

void ChooseTable(){

    cout << "MANAGEMENT INFORMATION\n";
    cout << "*************************MENU************************************\n";
    cout << "**  1. Infomation of employees.                                **\n";
    cout << "**  2. Infomation of departments.                              **\n";
    cout << "**  3. Location of departments.                                **\n";
    cout << "**  4. Infomation of projects.                                 **\n";
    cout << "**  5. Overtime information of employees.                      **\n";  
    cout << "**  6. Information of Employee has dependent .                 **\n";
    cout << "**  0. Exit                                                    **\n";
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
        default:
            break;
    } 
}