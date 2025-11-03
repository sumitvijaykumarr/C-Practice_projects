#include<iostream>
#include<vector>
#include<algorithm>

int main(){
    std::vector<int> vec = {10,2,4,2,6,77,45,21,0};
    std::vector<int>::iterator max = std::max_element(vec.begin(), vec.end());
    std::cout<<*max<<std::endl;
    std::cout<<std::distance(vec.begin(), max)<<std::endl;
    std::vector<int>::iterator min = std::min_element(vec.begin(), vec.end());
    std::cout<<*min<<std::endl;
    std::cout<<std::distance(vec.begin(), min);

    for(int v : vec){
        std::cout<<v<<",";
    }



    return 0;
}