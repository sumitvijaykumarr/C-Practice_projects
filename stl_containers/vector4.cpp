#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

std::vector<std::string> filter_duplicates(std::vector<std::string> list){
    std::unordered_map<std::string, int> duplicate_counts;
    std::vector<std::string> duplicate_entries;
    for(auto &i : list){
        duplicate_counts[i]++;
    }
    for(auto &i : duplicate_counts){

        if(i.second>1){
            duplicate_entries.push_back(i.first);
        }
    } 
    return duplicate_entries;
}
int main(){
    std::vector<std::string> names{"sumit", "prakash", "akshay", "anuj", "william", "sumit", "akshay", "anuj"};
    for(auto i : names){
        std::cout<<i<<",";
    }
        std::vector<std::string> duplicate_names = filter_duplicates(names);
             for(auto i : duplicate_names){
        std::cout<<i<<","<<std::endl;
    }

    return 0;
}
