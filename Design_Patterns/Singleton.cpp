#include<iostream>
#include<mutex>

class Singleton{
private:
    static Singleton* instance;
    Singleton();
   
public:
    void ShowMessage();
    static Singleton* getInstance();  
};

Singleton::Singleton(){
    std::cout<<"Constructor Invoked"<<std::endl;
}

Singleton* Singleton::getInstance(){
    if(instance == nullptr){
       instance = new Singleton();
    }
    return instance;
}

void Singleton::ShowMessage(){
    std::cout<<"ShowMessage is called"<<std::endl;
}

Singleton* Singleton::instance = nullptr;

int main(){
    //Singleton::instance = nullptr;
    Singleton* s1 = Singleton::getInstance();
    s1->ShowMessage();
    return 0;
}