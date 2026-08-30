#include <iostream>
using namespace std;

void resetSensorPairV1(int reading1, int reading2){//here we taking two parameter they are the argument of function call
    int temp = reading1;                           //since funtion is void and two local variable are swapping in it within the 
    reading1 = reading2;                           // scope of function here reading1 and reading2 are changed but only within 
    reading2 = temp;                           // the func. The original variables in main() are not changed.
}
void resetSensorPairV2(int& reading1, int& reading2){
    int temp = reading1;// Here reading1 and reading2 are references to the original variables.
    reading1 = reading2; // No separate copy is created.
    reading2 = temp;   // Therefore, changes made to reading1 and reading2
                       // directly affect the variables in main().
    
}
void resetSensorPairV3(int* reading1, int* reading2){
    int temp = *reading1;// reading1 and reading2 store the addresses of the original variables.
    *reading1 = *reading2;// Since we are modifying the values using their addresses,
    *reading2 = temp;// the original variables in main() are changed.
}

int main(){
    int A = 55;
    int B = 12;

    cout << "--- V1: Call by Value --" << endl;
    cout << "Before : A=" << A << "  B=" << B << endl;

    resetSensorPairV1(A, B);

    cout << "After  : A=" << A << "  B=" << B
         << "     <- values unchanged" << endl;

    cout << endl;

    cout << "--- V2: Call by Reference --" << endl;
    cout << "Before : A=" << A << "  B=" << B << endl;

    resetSensorPairV2(A, B);

    cout << "After  : A=" << A << "  B=" << B
         << "     <- values swapped" << endl;

    cout << endl;

    cout << "--- V3: Call by Pointer --" << endl;
    cout << "Before : A=" << A << "  B=" << B << endl;

    resetSensorPairV3(&A, &B);

    cout << "After  : A=" << A << "  B=" << B
         << "     <- values swapped back" << endl;


   return 0;
}