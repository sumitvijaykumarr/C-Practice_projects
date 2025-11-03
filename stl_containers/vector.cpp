#include <iostream>
#include <vector>

int main(){
     std::vector<int> v1{1,2,3,4,5,6};
     std::cout<<v1[2]<<std::endl;
     for(std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
     std::cout<<*it<<std::endl;
     std::cout<<v1.size();
     std::cout<<v1[5]<<std::endl;
     int i = 0;
     while(v1[i] != '\0'){
        std::cout<<v1[i]<<std::endl;
        i++;
     }
     std::string str1 = "sumit";
     std::vector<char> ch(str1.begin(), str1.end());
     for(std::vector<char>::iterator it = ch.begin(); it != ch.end(); ++it){
        std::cout<<*it<<"*";
     }

int arr[] = {159, 20, 30, 40};
int* p = arr + 3;
std::cout << *(p - 2)<<std::endl;
std::cout<<(*p+5);

std::vector<int> vec2 = {10,3,2,8,77,87,43,37,22};
//std::vector<int>::iterator 
auto max = std::max_element(vec2.begin(), vec2.end());
std::cout<<"Maximum element"<<*max;
return 0;
}