#include<iostream>

template <typename T, typename T1> 
T1 MaxNum(T x, T1 y){
    return (x>y)?x:y;
}

int main(){
    float k = 0;
    char c;
    k = MaxNum(3,5.5);
    c = MaxNum('a', 'n');

    std::cout<<k<<std::endl;
    std::cout<<c<<std::endl;
    return 0;
}