#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<iterator>
int main(){
    std::vector<int>v={1,2,3,4,5,9,7,8,0,11};
    auto printVector = [](const std::vector<int>&v,const std::string& message=" "){
      if(!message.empty())std::cout<<message<<":"<<std::endl;
      for(int num: v)std::cout<<num<<" ";
      std::cout<<std::endl;
    }; //lambda ifadeleri noktalı virgülle biter


    //all_of,any_of,non_of bu algoritmalar belli bir aralıktaki elemanların bir koşulu sağlayıp sağlamadığını kontrol eder.
    //hepsi pozitif mi?
    bool allpositive = std::all_of(v.begin(),v.end(),[](int x){return x>0;});
    std::cout<<"are all elements positive? "<<(allpositive?"true":"false")<<std::endl;
    //herhangi bir eleman 9 a eşit mi
    bool anyIsNine= std::any_of(v.begin(),v.end(),[](int x){return x==9;});
    std::cout<<"Is any elements 9 ? "<<(anyIsNine ? "true":"false")<<std::endl;

    //hibir eleman 10 dan büyük değil mi?
    bool noneGraderThenTen = std::none_of(v.begin(),v.end(),[](int x){return x>10;});
    std::cout<<"none graader than ten ? "<<(noneGraderThenTen ? "true": "false")<<std::endl;

    //for-each ile elemanları iki ile çarp
    std::for_each(v.begin(),v.end(),[](int& x){
        x*=2;
        std::cout<<x<<" ";
    });  //return yok bir değer döndürmez vektör üzerinde işlem yapar yazdırma elemanları değiştirme gibi
    std::cout<<std::endl;


    //find ile ilk 14 elementini bul
    auto it1= std::find(v.begin(),v.end(),14);
    if(it1!=v.end()){
        std::cout<<"14 finded and index : "<<std::distance(v.begin(),it1)<<std::endl;
    }else{
        std::cout<<"14 not found"<<std::endl;
    }
    //ilk çift elementi bul
    auto it2=std::find_if(v.begin(),v.end(),[](int x){
        return x%2==0;
    });
    if(it2!=v.end()){  //iterasyon
        std::cout<<"first even element: "<<*it2<<" index: "<<std::distance(v.begin(),it2)<<std::endl;
    }else{
     std::cout<<"there is not even number"<<std::endl;
    }
    v.push_back(7);
    v.push_back(6);
    v.push_back(6);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);




    //count:kaç tane 10 var  count_if:kaç tane tek sayı var
    int countfive= std::count(v.begin(),v.end(),10);
    std::cout<<"count of element of 10: "<<countfive<<std::endl;

    int countodd = std::count_if(v.begin(),v.end(),[](int x){return x%2 != 0;});
    std::cout<<"count of odd numbers: "<<countodd<<std::endl;



    //copy: tüm vektörü başka vektöre kopyala  copy_if:sadece çift sayıları kopyala
    std::vector<int>other_v(v.size()); // eger kopyalama işlemi yapılıcaksa boyutunu belirt yoksa segmantation fault hatası veriyor
    std::copy(v.begin(),v.end(),other_v.begin());
    printVector(other_v,"all elements copy to other_v vector");

    std::vector<int>even_v;
    std::copy_if(v.begin(),v.end(),std::back_inserter(even_v),[](int x){return x%2==0;});
    printVector(even_v,"even number copy to even_v vector");


    //generate algorithm 1 den başlayarak doldur
    std::vector<int>genereted(10);
    int start = 1;
    std::generate(genereted.begin(),genereted.end(),[&start](){return start++;});
    printVector(genereted,"genereted vector: ");

    //random sayılarla doldur 

}
