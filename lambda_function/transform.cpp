#include<iostream>
#include<vector>
#include<algorithm>

int main(){ 
    std::vector<int> numbers ={1,2,3,4,5,6,7,8,9,10,11};
    std::vector<int>squares;
    std::transform(numbers.begin(),numbers.end(),std::back_inserter(squares),[](int n) { return n*n ;});
    std::cout<<"squares vector including  ";
    for(auto n : squares){
        std::cout<< n << " ";
    }
    std::cout<<std::endl;


    return 0;
}