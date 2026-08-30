#include <iostream>
#include <cmath>
using namespace std;

double computeRMS(double* signal, int n){
// Returns sqrt( sum of (each element squared) / n )
    double sum = 0;

    for (int i = 0; i < n; i++) {
        sum = sum + (*(signal + i) * *(signal + i));
    }

    return sqrt(sum / n);
}

void normalise(double* signal, int n){
// Divides every element by the max absolute value in the array (in-place)
    double maxVal = 0;
    for(int i=0; i<n; i++){
        if(abs(*(signal + i)) > maxVal){
            maxVal = abs(*(signal + i));
        }
    }
    // dividing by abs val
    for(int i=0; i<n; i++){
        *(signal+i) = (*(signal+i))/maxVal;
    }
}

int countZeroCrossings(double* signal, int n){
// Returns count of positions where adjacent elements have opposite signs
    int count = 0;
    for(int i=0; i<n-1; i++){
        if(*(signal + i) < 0 && *(signal + i+ 1) > 0){
            count++;
        }
        if(*(signal + i) > 0 && *(signal + i+ 1) < 0){
            count++;
        }
    }
    return count;
}


void applyGain(double* signal, int n, double gainFactor){
// Multiplies every element by gainFactor (in-place)
    for (int i = 0; i < n; i++) {
        *(signal + i) = *(signal + i) * gainFactor;
    }
}

void printArray(double* signal, int n){
    cout <<"Printing the signal :"<<endl;
    for(int i=0; i<n; i++){
        cout<<*(signal + i)<< " ";
    }
}

int main() {

    double arr[50];
    double *ptr = arr;

    int length;
    double gainFactor;

    cout << "Enter the length of signal Array :" << endl;
    cin >> length;

    cout << "Enter the signal :" << endl;

    for (int i = 0; i < length; i++) {
        cin >> *(ptr + i);
    }

    // Original array
    printArray(ptr, length);

    // RMS
    cout << "RMS = " << computeRMS(ptr, length) << endl;

    // Zero crossings
    cout << "Zero Crossings = "
         << countZeroCrossings(ptr, length) << endl;

    // Before normalise
    cout << "Before normalise :" << endl;
    printArray(ptr, length);

    normalise(ptr, length);

    // After normalise
    cout << "After normalise :" << endl;
    printArray(ptr, length);

    // Gain
    cout << "Enter gain factor : ";
    cin >> gainFactor;

    // Before gain
    cout << "Before applyGain :" << endl;
    printArray(ptr, length);

    applyGain(ptr, length,2);

    // After gain
    cout << "After applyGain :" << endl;
    printArray(ptr, length);

    return 0;
}