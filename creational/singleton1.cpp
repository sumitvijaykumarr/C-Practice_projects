#include<iostream>


class Singleton{
    private:
        static Singleton* instance;
        static int counter;
        Singleton();
    public:
        static Singleton* getInstance();
        void ShowMsg(std::string msg);

};


void Singleton::ShowMsg(std::string msg){
    std::cout<<msg<<std::endl;
}

Singleton::Singleton(){
    counter++;
    std::cout<<"Constructor is invoked- "<<counter<<std::endl;
}

Singleton* Singleton::getInstance(){
    if(instance == nullptr){
        instance = new Singleton();
    }
    return instance;
}

Singleton* Singleton::instance = nullptr;
int Singleton::counter = 0;

int main(){
    Singleton* s1 = Singleton::getInstance();
    s1->ShowMsg("Msg from user 1");
    Singleton* s2 = Singleton::getInstance();
    s2->ShowMsg("Msg from user 2");
    return 0;
}