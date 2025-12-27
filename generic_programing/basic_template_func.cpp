#include<iostream>
template<typename T,typename U>
auto sum(T a, U b){   //SUM FONKSİYONU İÇİN PARAMETRE OLARAK İKİ TÜR KULLANIYORUZ ÖRNEGİN İNTEGER VE DOUBLE TOPLANIRSA HATA VERİRDİ
    return a+b;
}
template<typename T>
T get_big(T a,T b){
    return a>b ? a:b;
}
int main(){

std::cout<<sum(2.2,4.5)<<std::endl;
std::cout<<get_big('g','G')<<std::endl;
std::cout<<get_big(std::string("ruveyde"),std::string("melisa"))<<std::endl;  // dikkat eğer string için karşılaştırma yapılcaksa açıkça belirtilemli yoksa const char* türünde alır bu durumda da adreslerini karşılaştırır
std::cout<<get_big(10,9)<<std::endl;
}
