#include<iostream>
#include<fstream>

int main(){
    std::ofstream outfile("file.txt");
    outfile<<"hello world"<<std::endl;
    outfile.close();

    std::ifstream infile("file.txt"); //constructor ile neseneyi oluştururken dosyayı açtık
    std::string line;
    while(std::getline(infile,line)){
        std::cout<<line<<std::endl;
    }
    infile.close();

    std::fstream iofile;
    iofile.open("file.txt",std::ios::in | std::ios::out); //hem okuma hem yazma moduna open ile dosyaayı açtık






}
