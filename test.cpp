#include<iostream>
#include<climits>
using namespace std;

class Test{
private :

    int x ;
    int y ;
    static int z ;

public:
// 1
    Test(){
      x = 0;
      y = 0;
      z++;
    }
//2
    Test(int a , int b)
    {
        x = a;
        y = b;
        z++;

    }
 // copy constructor

    Test(Test &p)
    {
        x=p.x;
        y=p.y;
        z++;
    }


//5
    void set_Data(int a ,int b )

         {
             x = a ;
             y = b ;
         }

     int get_z(){

     return z ;
     }
     int get_x(){

       return x ;
     }
     int get_y()
      {
          return y ;
      }

  void display() const{

     cout<<"The values are :" <<endl;
     cout<<"x = " <<x<<endl;
     cout<<"y = " <<y<<endl;
     cout<<"z = " <<z<<endl;

  }


};
//3
int Test :: z = 0;

int main()
{
  Test num[5];
  int sum = 0;
  int maximum = INT_MIN;
  int maxindex ;
  int i ;
  num[0].set_Data(10,30);
  num[1].set_Data(20,40);
  num[2].set_Data(200,500);
  num[3].set_Data(70,80);
  num[4].set_Data(90,100);

  for(i=0;i<5;i++)
  {
      num[i].display();
  }

  for(i=0;i<5;i++)
  {
      sum = sum + num[i].get_x();
  }

   cout<<"The Summation of All X : " <<sum<<endl;
  for(i=0;i<5;i++)
  {
      if(maximum<num[i].get_y())
      {
          maximum = num[i].get_y();
          maxindex = i ;
      }
  }

   cout<<"The max value of y of all objects is  " <<maximum;
   cout<<" at object  " <<maxindex+1<<endl;




 return 0;

}

