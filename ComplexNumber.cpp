#include<iostream>
using namespace std;

class Complex{

int real;
int imag;

public :

  Complex operator +(Complex x)
    {
        Complex temp ;
        temp.real = real+x.real;
        temp.imag = imag+x.imag;
   return temp;
    }

    Complex operator -(Complex x)
    {

        Complex temp ;
        temp.real = real-x.real;
        temp.imag = imag-x.imag;
   return temp;
    }


  Complex operator *(Complex x)
    {

        Complex temp ;
        temp.real = real*x.real-imag*x.imag;
        temp.imag = real*x.imag+ imag*x.real;
   return temp;
    }


    Complex operator / (Complex x)
    {

        Complex temp ;

        temp.real = (real*x.real+imag*x.imag)/(x.real*x.real+x.imag*x.imag);
        temp.imag = (real*x.imag- imag*x.real)/(x.real*x.real+x.imag*x.imag);

   return temp;
    }

 friend Complex operator+(int x , Complex y);
 friend istream& operator >>(istream &in , Complex &a );
 friend ostream& operator << (ostream &out , Complex &a );

};
Complex operator+(int x , Complex y)
{
    Complex temp ;
     temp.real = y.real+x ;
     temp.imag  = y.imag ;

     return temp ;

}

istream& operator >>(istream &in , Complex &a )
{
    cout<<"Enter real part"<<endl;
    in>>a.real;
    cout<<"Enter imaginary part"<<endl;
    in>>a.imag;


   return in ;
}
ostream& operator << (ostream &out , Complex &a )
{

    out<<a.real<<"+"<<a.imag<<"i"<<endl;

   return out ;
}

int main()
{
    Complex a , b ,c;
    cin>>a;
    cin>>b ;
    c = a-b;

    cout<<"The result is "<<endl;
    cout<<c ;

    //int abc = 5 + "xyz";//Built in data cannot be overloaded;
}




