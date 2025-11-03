#include<iostream>

template<typename T1, typename T2, typename T3> 
class trial{
public:
    T1 x;
    T2 y;
    T3 z;
trial(T1 l, T2 m, T3 n);
void getValues();
~trial();
};



template<typename T1, typename T2, typename T3> 
trial<T1, T2, T3>::trial(T1 l, T2 m, T3 n): x(l), y(m), z(n){} 

template<typename T1, typename T2, typename T3> 
trial<T1, T2, T3>::~trial(){}



template<typename T1, typename T2, typename T3> 
void trial<T1, T2, T3>::getValues(){
std::cout<<x<<std::endl;
std::cout<<y<<std::endl;
std::cout<<z<<std::endl;
}




int main(){
    trial t(2, 45.606, "sumit");
    t.getValues();
    return 0;
}
