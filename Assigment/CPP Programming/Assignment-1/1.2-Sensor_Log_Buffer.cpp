#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int num;

    cout << "Enter the N : " << endl;
    cin >> num;

    double arr[100];

    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    cout << "Readings Entered :  " << num << endl;
    cout << "Valid readings    :  ";

    int skipped = 0;
    int indexFC = -1;
    double firstCrt = 0;

    double mini = 0;
    double maxi = 0;
    double sum = 0;

    bool firstValid = true;
    bool foundCritical = false;

    for (int i = 0; i < num; i++) {

        if (arr[i] < 0) {
            skipped++;
            continue;
        }

        cout << arr[i] << "  ";

        sum = sum + arr[i];

        if (firstValid) {
            mini = arr[i];
            maxi = arr[i];
            firstValid = false;
        } else {
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        }

        // Find FIRST critical reading
        if (arr[i] >= 45 && !foundCritical) {
            indexFC = i;
            firstCrt = arr[i];
            foundCritical = true;
        }
    }

    int validReadings = num - skipped;

    cout << endl;
    cout << "Skipped (errors)   : " << skipped << endl;

    if (foundCritical) {
        cout << "First CRITICAL     : Index " << indexFC
             << " -> " << firstCrt << endl;
    } else {
        cout << "First CRITICAL     : None" << endl;
    }

    if (validReadings > 0) {
        double avg = sum / validReadings;

        cout << "Min : " << mini << "     ";
        cout << "Max : " << maxi << "     ";
        cout << "Avg : " << avg << endl;
    } else {
        cout << "No valid readings available." << endl;
    }

    // count readings per category
    int r_normal = 0;
    int r_critical = 0;
    int r_warning = 0;
    int r_shutdown = 0;
    for(int i =0; i<num; i++){
        if(arr[i]<0){
            continue;
        }
        else if(arr[i]>0  && arr[i]<30){
            r_normal++;
        }
        else if(arr[i]>=30  && arr[i]<45){
            r_warning++;
        }
        else if(arr[i]>=45  && arr[i]<60){
            r_critical++;
        }
        else{
            r_shutdown++;
        }
    } 
    cout <<"Normal : "<<r_normal<<"   ";
    cout <<"Warning : "<<r_warning<<"   ";
    cout <<"Critical : "<<r_critical<<"   ";
    cout <<"Shutdowwn : "<<r_shutdown<<endl;

    return 0;
}