#include<iostream>
#include<vector>

int main(){
   auto vector = std::vector<int>{10,20,30,40,50};
   for(auto x : vector){
      std::cout<<x<<std::endl;
   }
return 0;

}