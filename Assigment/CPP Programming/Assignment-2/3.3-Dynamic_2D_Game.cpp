#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    int R,C;

    cout << "Enter rows: ";
    cin >> R;

    cout << "Enter columns: ";
    cin >> C;

    //Creating 2D dynamic array 
    int ** game = new int *[R];
    for(int i=0; i<R; i++){
        game[i] = new int[C];
    }

    // Taking input in 2D array
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            game[i][j] = rand() % 5;
        }
    }
    int grassC = 0;
    int waterC = 0;
    int mountainC = 0;
    int forestC = 0;
    int dungeonC = 0;

    // Printing  2D array
    cout<<"=====  GAME MAP (3 X 4)  ====="<<endl; 
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout<<game[i][j]<<" ";
            switch(game[i][j]){
                case 0 : 
                    grassC++;
                    break;
                case 1 :
                     waterC++;
                     break;
                case 2 :
                    mountainC++;
                    break;
                case 3 :
                    forestC++;
                    break;
                case 4:
                    dungeonC++;
                    break;
                default:
                    break; 
            }
        }
        cout<<endl;
    }

    cout <<endl<< "Legend:  ";
    cout << "0=Grass  1=Water  2=Mountain  3=Forest  4=Dungeon" << endl;


    cout << "Tile Count:" << endl;
    cout << "Grass    : " <<grassC<< endl;
    cout << "Water    : " <<waterC<< endl;
    cout << "Mountain : " <<mountainC<< endl;
    cout << "Forest   : " <<forestC<< endl;
    cout << "Dungeon  : " <<dungeonC<< endl;

    //Free memory 
    for(int i=0; i<R; i++){
        delete[] game[i];
    }
    delete[] game;

    return 0;
}