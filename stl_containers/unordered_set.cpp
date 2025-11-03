#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>
int main(){
    std::unordered_set<int> set1{2,3,4,56,1,0,5,7,0,99,23};
    int count{0};
    for( const int &i : set1){
        count++;
        if(i == 56){
            std::cout<<"56 found at index "<<count<<std::endl;
            break;
        }
    }
    //To count the occurance of an element in a vector
    std::vector<int> vec1{1,2,2,2,3,4,5,6};
    std::cout<<"occurance if present or not = "<<std::count(vec1.begin(), vec1.end(), 2)<<std::endl;
    // if(set1.find(56) == set1.end()){
    //     std::cout<<"Number does not exist"<<std::endl;
    // }
    // else{
    //     std::cout<<"Number does not exist"<<std::endl;
    //     std::cout<<set1.insert(56).first;
    // }
    std::find()---- To check if the element present, if present returns iterator [vector, set]
    std::equal_range()--- To check if ele is present, for multiple occurance in case of "multiset", a pair object is returned whose .first will give lower index and .second will give upper index
    std::distance()----To get the index of particular element from begining for vector, sets
    Simple for loop with counter is also usefull for determining the index
    std::swap()---To swap the vectors.
    == / std::equal(vec1.begin(), vec1.end(). vec2.begin)--To check if vectors r equal
    std::sort(vec1.begin(), vec1.end())--- To sort
    std::set<int> s1(v1.begin(), v1.end())---To cnvert vector to set

    Finding all values for a key (same for both)
    auto range = marks.equal_range("Sumit");
        for (auto it = range.first; it != range.second; ++it) {
            std::cout << it->first << " : " << it->second << std::endl;
        }


    return 0;
}