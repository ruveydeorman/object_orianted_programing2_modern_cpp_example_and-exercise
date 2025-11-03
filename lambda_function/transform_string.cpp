#include<iostream>
#include<cctype>
#include<vector>
#include<string>
#include<algorithm>

int main(){
  std::vector<std::string>words = {"ruveyde","orman"};
  std::cout<<"words without toupper : ";
  for(std::string & s : words){
    std::cout<<s<<" ";
  }
  std::cout<<std::endl;

  std::transform(words.begin(),words.end(),words.begin(),[](std::string& str){
      for(char& c : str){
        c = toupper(c);
      }
      return str;
  });
  std::cout<<"words with toupper : ";
  for(std::string & s : words){
    std::cout<<s<<" ";
  }

std::cout<<std::endl;


    return 0;
}