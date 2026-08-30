#include <iostream>
#include <string>
using namespace std;

int main(){
    double input;
    cout<<"Enter the Input Reading ::"<<endl;
    cin>>input;

    double fahrenheit = (input*9/5) + 32;
    
    cout << "Temperature    : " << input << "\u00B0C  /  "<<fahrenheit<<"\u00B0F" << endl;
    // cout<<"Temprature  : " <<input <<"    /     "<<fahrenheit<<endl;

    int statusCode;
    if(input < 0){
        statusCode = -1;
    }
    else if(input >= 0 && input <= 29){
        statusCode = 0;
    }
    else if(input >= 30 && input <= 44){
        statusCode = 1;
    }
    else if(input >= 45 && input <= 59){
        statusCode = 2;
    }
    else{
        statusCode = 3;
    }

    switch(statusCode){

        case -1: 
            cout<<"Status         :  SENSOR_ERROR "<<endl;
            cout<<"Action         :  Sensor fault -- check wiring";
            break;
        case 0:
            cout<<"Status         :  NORMAL "<<endl; 
            cout<<"Action         :  No action required";
            break;
        case 1: 
            cout<<"Status         :  WARNING "<<endl;
            cout<<"Action         :  Alert sent to supervisor";
            break;
        case 2: 
            cout<<"Status         :  CRITICAL "<<endl;
            cout<<"Action         :  Cooling system triggered";
            break;
        case 3: 
            cout<<"Status         :  SHUTDOWN "<<endl;
            cout<<"Action         :  Emergency shutdown initiated";
            break;
        default:
            cout<<"Invalid Input::";
            break;
    }
    cout<<endl;

    string reading = (input > 25) ? "Above Average " : "Below Average";
    cout<<"Reading        :  "<<reading<<endl;

    return 0;
}