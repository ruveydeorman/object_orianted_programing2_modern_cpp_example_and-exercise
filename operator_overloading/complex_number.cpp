#include<iostream>
class Complex{
    double real;
    double imag;
public:
    Complex(double r=0.0,double i=0.0):real(r),imag(i){}
    Complex(const Complex& other){
        real=other.real;
        imag=other.imag;
    }
    Complex& operator=(const Complex& other){
      real=other.real;
      imag=other.imag;
      return *this;
    }
   Complex& operator+=(const Complex& other){
     real+=other.real;
     imag+=other.imag;
     return *this;
   }
   Complex& operator-=(const Complex& other){
    real-=other.real;
    imag-= other.imag;
    return *this;
   }
   Complex& operator*=(const Complex& other){
    real*=other.real;
    imag*=other.imag;
    return *this;
   }
  
   
   friend Complex operator*(const Complex& left,const Complex& right);
   friend Complex operator-(const Complex& left, const  Complex& right);
   friend Complex operator+(const Complex& left, const Complex& right);
   void print()const{
    std::cout<<"complex number:"<<real<<" + "<<"i"<<imag<<std::endl;
   }
  
};
Complex operator+(const Complex& left, const Complex& right){
    Complex result =left; //copy constructor kullanır
    result += right;
    return result;
}
Complex operator-(const Complex& left,const Complex& right){
  Complex result=left;
  result-=right;
  return result;
}
Complex operator*(const Complex& left,const Complex& right){
  Complex result= left;
  result*=right;
  return result;
}

int main(){
  Complex n1(2,3),n2(4,5),n3,n4,n5;
  n3= n1;
  n3= n1+n2;
  n4=n2-n1;
  n5=n1*n2;
  n1.print();
  n2.print();
  n3.print();
  n4.print();
  n5.print();




    return 0;
}
