#include <sstream>
#include <iostream>
#include<string>

int main(){
    std::string line;
    std::getline(std::cin,line);
    std::cout<<line<<std::endl;

    std::stringstream ss("colomn1\ncolomn2\ncolomn3\n");
    while(std::getline(ss,line)){
        std::cout<<line<<std::endl;
    }
    
    std::stringstream data("hello,im ruveyde,im 22 years old..");
    while(std::getline(data,line,',')){
        std::cout<<line<<std::endl;
    }



    return 0;
}
