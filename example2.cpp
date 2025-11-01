#include<iostream>
#include<vector>
int main(){
  auto vector = std::vector<double>{1.2,3.3,3.4};
  for(auto& x:vector){
    x *= 2;
    std::cout<<x<<" ";
  }
  std::cout<<std::endl;

    return 0;
}