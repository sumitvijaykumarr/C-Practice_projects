#include"iostream"

int main(){
    int *ptr;
    int a = 55;
    ptr = &a;
    std::cout<<*ptr<<std::endl;
    std::cout<<*ptr++<<std::endl;
    std::cout<<*ptr<<std::endl;

    std::cout<<*(ptr++)<<std::endl;
    return 0;
}