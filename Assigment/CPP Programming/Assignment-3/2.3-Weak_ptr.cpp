#include<iostream>
#include<string>
#include <memory>
using namespace std;

class AudioClip{
    string name;
    float num;

    public:
    
    AudioClip(string n,float f){
        this->name = n;

        this->num = f;

        cout<<"[AudioClip Compiled]"<<endl;
    }

    string getName() const {
        return name;
    }

    ~AudioClip(){
        cout<<"[AudioClip Destroyed]"<<endl;
    }
        
};

int main(){
        auto audio = make_shared<AudioClip>("explosion", 3.5);
        weak_ptr<AudioClip> observer = audio;

        if (auto clip = observer.lock())
            cout << "Clip alive: " << clip->getName() << endl;


        audio.reset();    // unload

        if (observer.expired())
            cout << "Clip already unloaded." << endl; 
    
    return 0;
}