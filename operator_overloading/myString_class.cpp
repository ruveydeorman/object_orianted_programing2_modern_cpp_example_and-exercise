#include<iostream>
#include<cstring>
#include<vector>
class myString{
private:
    char* data;
    size_t length;
public:
    //constructor
    myString(const char* str=" "){
        length=std::strlen(str);
        data=new char[length+1];
        strcpy(data,str);
    }
    //destructor
    ~myString(){
        delete[] data;
    }
    //copy constructor
    myString(const myString& other){
        length=other.length;
        data=new char[length+1];
        strcpy(data,other.data);
    }
    myString& operator=(const myString& other){
        if(this!=&other){  //self-assignment control adres karşılaştırması
            char* newdata= new char[other.length+1];//exception safety açısından, önce kopyayı oluşturup sonra silmek daha iyidir.adres ayırmada sorun oluşursa nesnemiz hala elimizde olur
            strcpy(newdata,other.data);
            delete[] data;
            data=newdata; 
            length=other.length;     
        }
        return *this;
            
    }
    myString( myString&& other)noexcept : data(other.data),length(other.length) { //move semantic için const olmayan referanslar gerekir const read-only olur
         other.data=nullptr;
         other.length=0;
    }

    myString& operator=(myString&& other)noexcept{
         if(this!=&other){
            delete[] data;
            data=other.data;
            length=other.length;
            other.data=nullptr;
            other.length=0;
         }
         return *this;
    }
    myString& operator+=(const myString& other){  //ilk önce uzunluk ve veriyi başak değişkene atadık sonra datayı sildik 
        size_t new_length=length+other.length;
        char* newdata= new char[new_length+1];
        std::strcpy(newdata,data);
        std::strcat(newdata,other.data);
        delete[] data;
        data=newdata; //Bu, data'nın artık newdata'nın işaret ettiği bellek adresini göstermesi demektir.
        length=new_length;
        return *this;
    }
   //array subscript operator
   char& operator[](size_t index){
       return data[index];
   }
   //locig operator
    friend bool operator==(const myString& left,const myString& right);
    friend bool operator!=(const myString& left,const myString& right);
    friend bool operator<(const myString& left,const myString& right);
    friend bool operator>(const myString& left,const myString& right);
    friend bool operator<=(const myString& left,const myString& right);
    friend bool operator>=(const myString& left,const myString& right);
    friend std::ostream& operator<<(std::ostream& os ,const myString& s);
    friend std::istream& operator>>(std::istream& is, myString& s);
    operator char*()const{
        return data;
    }
    operator std::string()const{
        return std::string(data);
    }
    
    
};
//+ operator overloading
myString operator+(const myString& left,const myString& right){
    myString result=left;
    result+=right;
    return result;
}
bool operator==(const myString& left,const myString& right){
    return std::strcmp(left.data,right.data)==0;
}
bool operator!=(const myString& left,const myString& right){
    return std::strcmp(left.data,right.data)!=0;
}
bool operator<(const myString& left,const myString& right){
    return std::strcmp(left.data,right.data)<0;
}
bool operator>(const myString& left,const myString& right){
    return std::strcmp(left.data,right.data)>1;
}
bool operator<=(const myString&left,const myString& right){
    return std::strcmp(left.data,right.data)<=0;
}
bool operator>=(const myString& left,const myString& right){
    return std::strcmp(left.data,right.data)>=0;
}
std::ostream& operator<<(std::ostream& os,const myString& s){
    os<<s.data;
    return os;
}
std::istream& operator>>(std::istream& is, myString& s){
    //geçici buffer
    std::vector<char>buffer;
    char ch;
    while(is.get(ch)&&std::isspace(ch)){ //akıştaki karakaterleri okur ve boşluk karakteri kontrolü yapar boşluk karakteri atlanır
        //boşlukları atlar
    }
    if(is){
        buffer.push_back(ch);
        while(is.get(ch)&&!std::isspace(ch)){
            buffer.push_back(ch);
        }
        if(is){
            is.unget();//aldığı son karakteri bırakır içine argüman yazılmaz
        }
    }
    delete[] s.data;
    s.length=buffer.size();
    s.data=new char[s.length+1];
    for(size_t i=0;i<s.length;++i){
        s.data[i]=buffer[i];
    }
    s.data[s.length]='\0';
    
    return is;
}
int main(){
myString s("ruveyde");
myString n("orman");
myString str,x;
str=s;
s+=n;
std::cin>>x;
std::cout<<x<<std::endl;
std::cout<<s<<std::endl;
if(str==s){
    std::cout<<"str equal to s"<<std::endl;
}else{
    std::cout<<"str not equal to s"<<std::endl;
}
if(str==n){
    std::cout<<"str equal to s"<<std::endl;
}else{
    std::cout<<"str not equal to s"<<std::endl;
}


}

