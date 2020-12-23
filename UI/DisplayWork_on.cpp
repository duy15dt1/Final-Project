#include "DisplayWork_on.h"

void DisplayWorkon(Work_on_Data& workondata){
    for (int i = 0; i < workondata.GetMaxId();i++){
        Work_on temp;
        temp = workondata.Get(i);
        cout <<temp.GetId()<<temp.ToString()<<endl;
    }
}