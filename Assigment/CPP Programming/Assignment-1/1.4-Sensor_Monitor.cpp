#include <iostream>
using namespace std;

int main(int args , char* argv[]){

    //checking command line argument 
    if( args != 4){
        cout << "Usage   : ./sensor_monitor" << endl;
        cout << "Error   : Missing arguments" << endl;
        return 1;
    }

    //args string to int 
    int wg = stoi(argv[1]);
    int ct = stoi(argv[2]);
    int num_read = stoi(argv[3]);

    //condition check 
    if(wg>=ct){
        cout << "Error   : Warning threshold must be less than critical threshold" << endl;
        return 1;
    }
    if(num_read<1 || num_read > 500){
        cout << "Error   : Number of readings must be between 1 and 500" << endl;
        return 1;
    }
    //print args
    cout << "Config  : Warn=" << wg
         << "C  Critical=" << ct
         << "C  Readings=" << num_read << endl;

    //calculate temprature with counts
    int normal = 0;
    int warning = 0;
    int criticalCount = 0;
    int shutdown = 0;

    // Step 7: Generate and classify readings
    for (int i = 0; i < num_read; i++) {

        int temp = rand() % 70;

        if (temp < wg) {
            normal++;
        }
        else if (temp < ct) {
            warning++;
        }
        else if (temp < 60) {
            criticalCount++;
        }
        else {
            shutdown++;
        }
    }

    cout << "Results : "
         << "  Normal:" << normal
         << "  Warning:" << warning
         << "  Critical:" << criticalCount
         << "  Shutdown:" << shutdown
         << endl;
         
    return 0;

}