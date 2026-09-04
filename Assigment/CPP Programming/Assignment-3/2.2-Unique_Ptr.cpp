#include<iostream>
#include<string>
#include <memory>
using namespace std;

class Texture{
    string name;
    int width;
    int height;

    public:
    Texture(string name,int w, int h){
        this->name = name;

        this-> width = w;
        this ->height = h;

        cout<<"[Tecture Loaded]"<<endl;
    }

    ~Texture(){
        cout<<"[Texture Released]"<<endl;
    }

    void displayTexture(){ 
        cout << "Texture : " << name << endl;
        cout << "Size    : " << width << " x " << height << endl;
    } 
        
};

int main(){

    auto text  =make_unique<Texture>("player_sprite", 512,512);
    text->displayTexture();

    // 3. Attempt to copy unique_ptr
    // auto textureCopy = text2;
    // ERROR: unique_ptr cannot be copied because it allows only one owner.

    // Transfer ownership using move()
    auto text2 = move(text);

    cout << "texture is nullptr: "
         << (text == nullptr ? "Yes" : "No") << endl;

    cout << "Text through text2:" << endl;
    text2->displayTexture();

    // text2 goes out of scope at the end of main()
    // Destructor will be called automatically.


    return 0;
}