#include<iostream>
#include<algorithm>
#include<array>
int main(){
std::array<int,5>arr={2,3,1,5,4};
std::array<int,5>arr2={7,8,9,0,6};

for(auto it=arr.begin();it!=arr.end();++it){   
   std::cout<<*it<<" ";
}
std::cout<<std::endl;
for(auto rit=arr.rbegin();rit!=arr.rend();++rit){
    std::cout<<*rit<<" ";
}
std::cout<<std::endl;

std::cout<<"size: "<<arr.size()<<std::endl;

std::cout<<"first element: "<<arr.front()<<std::endl;
std::cout<<"last element: "<<arr.back()<<std::endl;
std::cout<<"eleemnt at index 3: "<<arr[3]<<std::endl;

arr.fill(10);
for(auto it=arr.begin();it!=arr.end();++it){ 
   std::cout<<*it<<" ";
}
std::cout<<std::endl;
arr.swap(arr2);
for(auto it=arr.begin();it!=arr.end();++it){  
   std::cout<<*it<<" ";
}
std::cout<<std::endl;


}
