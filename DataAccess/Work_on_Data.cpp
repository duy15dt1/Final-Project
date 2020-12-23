#include "Work_on_Data.h"
//     Work_on_Data workondata;
//     Work_on w1(123456789,1,32.5);
//     Work_on w2(123456789,2,7.5);
//     Work_on w3(666884444,3,40.0);
//     Work_on w4(453453453,1,20.0);
//     Work_on w5(453453453,2,20.0);
//     Work_on w6(333445555,2,10.0);
//     Work_on w7(333445555,3,10.0);
//     Work_on w8(333445555,10,10.0);
//     Work_on w9(333445555,20,10.0);
//     Work_on w10(999887777,30,30.0);
//     Work_on w11(999887777,10,10.0);
//     Work_on w12(987987987,10,35.0);
//     Work_on w13(987987987,30,5.0);
//     Work_on w14(987654321,30,20.0);
//     Work_on w15(987654321,20,15.0);
//     Work_on w16(987987987,20,-1);
//Contructor function of Work_on_Data
Work_on_Data::Work_on_Data(){
    _maxId = 0;
    _data.resize(0);
}
//GetMaxId() is a function that get the maximum ID of Work_on data
int Work_on_Data:: GetMaxId(){
    return _maxId;
}
// PushBack(Work_on) is a function that push one Work_on data in the back of _data vector and return maximun ID of the current _data vector
int Work_on_Data:: PushBack(Work_on w){
    if (_maxId < w.GetId()){
        _maxId = w.GetId();
    }
    _data.push_back(w);
    return _maxId;
}
//Get(int i) is a function that get the Work_on data at i position of _data vector
Work_on Work_on_Data:: Get(int i){
    return _data[i];
}