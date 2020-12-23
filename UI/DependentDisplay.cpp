#include "DependentDisplay.h"

void DisplayDependent(DependentData& dependentData){
    for(int i=0; i<dependentData.GetMaxId(); i++){
        Dependent d = dependentData.Get(i);
        cout <<d.GetId()<<" "<< d.ToString()<<endl;
    }
}

void DisplayDependentData()
{
    Dependent d1(333445555, "Alice", 'F', "1986-04-05", "DAUGHTER");
    Dependent d2(333445555, "Theodore", 'M', "1983-10-25", "SON");
    Dependent d3(333445555, "Joy", 'F', "1958-05-03", "SPOUSE");
    Dependent d4(987654321, "Abner", 'M', "1942-02-28", "SPOUSE");
    Dependent d5(123456789, "Micheal", 'M', "1988-01-04", "SON");
    Dependent d6(123456789, "Alice", 'F', "1988-12-30", "DAUGHTER");
    Dependent d7(123456789, "Elizabeth", 'F', "1967-05-05", "SPOUSE");
    
    DependentData dependentData;
    dependentData.PushBack(d1);
    dependentData.PushBack(d2);
    dependentData.PushBack(d3);
    dependentData.PushBack(d4);
    dependentData.PushBack(d5);
    dependentData.PushBack(d6);

    DisplayDependent(dependentData);
}