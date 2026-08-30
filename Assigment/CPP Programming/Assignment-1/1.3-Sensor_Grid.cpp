#include <iostream>
#include<algorithm>
using namespace std;

int main(){

    double arr[3][3];

    //input from user 
    cout<<"Enter the values:::"<<endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];
        }
    }

    double h_Room = arr[0][0];
    int f_Ind = 0;
    int r_Ind = 0;
    int warn = 0;


    double avgMax= 0;
    int f_maxInd = 0;


    cout<<"\tRoom1\tRoom2\tRoom3"<<endl;

    for(int i=0; i<3; i++){
        double sum = 0;
        cout<<"Floor "<<i+1<<"\t:\t";
        for(int j=0; j<3; j++){
            cout<<arr[i][j]<<" \t";

            sum+= arr[i][j];

            if(h_Room<arr[i][i]){
                h_Room = arr[i][j];
                f_Ind = i;
                r_Ind = j;
            }
            if(arr[i][j]>=30){
                warn++;
            }

        }
        cout<<endl;
        if(avgMax<sum/3){
            f_maxInd = i;
            avgMax = sum/3;
        }
    }
    
    cout<<"Hottest Room  : Floor "<<f_Ind+1<<",\tRoom "<<r_Ind+1<<" -> "<<h_Room<<endl;
    cout<<"Hottest Floor : Floor "<<f_maxInd+1<<",\t("<<avgMax<<")"<<endl;
    cout<<"Rooms at WARING or above  : "<<warn<<endl; 

}