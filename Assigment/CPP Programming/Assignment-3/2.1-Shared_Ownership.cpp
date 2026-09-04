#include<iostream>
#include<string>
#include <memory>
using namespace std;

class Shader{
    string name;
    string type;

    public:
    Shader(string name,string type){
        this->name = name;

        if (type == "vertex" || type == "fragment") {
            this->type = type;
        }

        cout<<"[Shader Compiled]"<<endl;
    }

    ~Shader(){
        cout<<"[Shader Destroyed]"<<endl;
    }

    int getReferenceCout(const shared_ptr<Shader> &s){
        int count = s.use_count();
        return count;
    }
     
        
};

int main(){
        auto shader =make_shared<Shader>("main_vert", "vertex");
        cout << "Ref count: " << shader.use_count() << endl;   
        {
        auto rendererRef = shader;
        cout << "Ref count: " << shader.use_count() << endl;  
    
        auto editorRef   = shader;
        cout << "Ref count: " << shader.use_count() << endl;  
        }
    
        cout << "Ref count: " << shader.use_count() << endl; 
    return 0;
}