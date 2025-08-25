#include"iostream"

int main(){
    int *ptr;
    int a = 55;
    ptr = &a;
    std::cout<<*ptr<<std::endl;
    std::cout<<*ptr++<<std::endl;
    std::cout<<a<<std::endl;
    std::cout<<*ptr<<std::endl;

    std::cout<<*(ptr++)<<std::endl;
    std::cout<<(*ptr)++<<std::endl;

    int arr[] = {3,4,5,6,7};
    std::cout<<*arr<<std::endl;
    std::cout<<*arr+1<<std::endl;
    std::cout<<arr<<std::endl;
    std::cout<<++*arr<<std::endl;
    
    return 0;
}