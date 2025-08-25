#include "iostream"
#include "mutex"
#include "thread"
#include "chrono"

std::mutex m;
using namespace std::chrono_literals;
int i;
int j;
void driving(std::string name){
    m.lock();
    j= 4;
    while(j){
    std::this_thread::sleep_for(200ms);
    std::cout<<name<<" is driving a car...."<<std::endl;
    j--;
    }
    m.unlock();
}

void eating(std::string name){
    m.lock();
    i = 5;
    while(i){
    std::this_thread::sleep_for(200ms);
    std::cout<<name<<" is eating sandwich...."<<std::endl;
    i--;
    }
    m.unlock();
}

int main(){
    std::thread t1(driving, "Harish");
    std::thread t2(eating, "Harish");

    t1.join();
    t2.join();
    return 0;
}