#include<iostream>
#include<cstring>
 class myString{
 private:
    char* data;
    size_t length;
 public:
  myString(const char* str=" "){
    length=strlen(str);
    data=new char[length+1];
    strcpy(data,str);
  }
  ~myString(){
    delete[] data;
  }
  myString& operator=(const myString& other){
   
    if(this!= &other){ //self-assignment control
        char* newData = new char[other.length +1];//copy other object data for exeption safety(bellek ayırmada sorun çıkarsa nesnenin önceki durumunu korumak için)
        strcpy(newData,other.data);
        delete[] data;
        data=newData;
        length= other.length;
    }
    return *this;
  }
  void print(){
   for(int i=0;i<length;i++){
    std::cout<<data[i];
   }
   std::cout<<std::endl;
    }
 };


 int main(){
    myString str("ruveyde");
    myString str2("melisa");
    str= str2;
    str.print();
    return 0;
 }

