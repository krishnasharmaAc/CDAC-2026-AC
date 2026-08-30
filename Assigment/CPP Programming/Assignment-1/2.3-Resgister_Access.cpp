#include <iostream>
using namespace std;

int main(){
    int statusReg  = 0b10110001;    // Read-only from firmware side
    int controlReg = 0b00000000;   // Firmware writes here
    int dataReg    = 0b11001010;   // For reassignment demo


    // REGPTR1 : Pointer to const integer
    cout<<endl<<"***********************************"<<endl;
    cout<<"|||||pointer to constant integer||||||"<<endl;

    const int * regPtr1 = &statusReg;
    cout << "regPtr1 value : " << *regPtr1 << endl;
    cout << "regPtr1  : " << regPtr1 << endl;

    //*regPtr1 = 101;
    //cout << "regPtr1 value : " << *regPtr1 << endl;
    // ERROR: Cannot modify the value through a pointer-to-const.

    regPtr1 = &controlReg;
    cout << "regPtr1 : " << regPtr1 << endl;
    // ALLOWED: A pointer-to-const CAN be reassigned.
    // Therefore, this is NOT an error.


    //REGPTR2 : Constant pointer to integer
    cout<<endl<<"***********************************"<<endl;
    cout<<"|||||Constant pointer to integer||||||"<<endl;
    
    int * const  regPtr2 = &controlReg;
    cout << "regPtr2 value : " << *regPtr2 << endl;
    cout << "regPtr2  : " << regPtr2 << endl;

    *regPtr2 = 101;
    cout << "controlReg after write : " << controlReg << endl;
    //here value is not const it can changed

    // regPtr2 = &dataReg;
    // ERROR: regPtr2 is a const pointer.
    // Its address cannot be changed after initialization.


    // REGPTR3 : Constant pointer to constant integer
    cout<<endl<<"***********************************"<<endl;
    cout<<"|||||Constant pointer to constant integer||||||"<<endl;
    
    const int * const regPtr3 = &dataReg;
    cout << "regPtr3 value : " << *regPtr3 << endl;

    // *regPtr3 = 50;
    // ERROR: Cannot modify the value because it is pointed
    // to through a pointer-to-const.

    // regPtr3 = &dataReg;
    // ERROR: regPtr3 itself is a const pointer,
    // so it cannot be reassigned.



    return 0;
}