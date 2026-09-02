#include <iostream>
#include <string>
using namespace std;

// Global variable
int level = 1;

// Nested namespace
namespace Engine {
    namespace Audio {
        void playSound(string name) {
            cout << "Playing: " << name << endl; 
        } 
    }
}

int main() {

    // Local variable
    int level = 10;

    // Local level
    cout << "Player Level: " << level << endl;

    // Global level using scope resolution operator
    cout << "Game Difficulty Level: " << ::level << endl;

    // Calling function using full namespace path
    Engine::Audio::playSound("sword_clash");

    return 0;
}