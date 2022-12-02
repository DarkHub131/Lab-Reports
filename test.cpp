#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream newfile;
    newfile.open("Bhargav.txt", ios::out);
    if (newfile.is_open())
        {
        newfile<<"Hello ,This is my first line"<<endl;
        newfile<<"This is my second line in my file"<<endl;
        newfile.close();
    }
    system("pause");
}