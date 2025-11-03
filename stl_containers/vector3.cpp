#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

//code to identify the duplicate elements

std::vector<int> filter_duplicates(std::vector<int> vec1);
int main(){
    std::vector<int> vec = {2,2,3,4,5,8,3,6,7,8,5};
    std::vector<int> result = filter_duplicates(vec);
    
    for(int v : result){
        std::cout<<v<<",";
    }
    
    return 0;
}
std::vector<int> filter_duplicates(std::vector<int> vec1){
    std::unordered_map<int, int> counts;
    std::vector<int> duplicates;
    for(int element : vec1){
        counts[element]++;
    }
    for( auto &c : counts){
        if(c.second > 1){
            duplicates.push_back(c.first);
        }
    }
    return duplicates;
}