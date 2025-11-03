#include<iostream>
#include<vector>
#include<algorithm>

int main (){
   std::vector<int>vec = {2,3,4,5,6,7,8,9};
   std::vector<int>copy_vec;
   std::copy_if(vec.begin(),vec.end(),std::back_inserter(copy_vec),[](int n)
                 {
                    return n %2 == 0;
                 });
    std::cout<<" copy vector elements : " ;            
    std::for_each(copy_vec.begin(),copy_vec.end(),[](int n)
                 {
                   std::cout<<n<<" ";  
                 });             

    return 0;
}