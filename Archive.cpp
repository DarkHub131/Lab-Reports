#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;
class student
{
private:
    string name;
    int roll;
    string dept;

public:
    void set(string name, int roll, string dept)
    {
        this->name = name;
        this->roll = roll;
        this->dept = dept;
    }

    void displayinfo()
    {
        cout << "\n\tName : " << name << endl;
        cout << "\tRoll : " << roll << endl;
        cout << "\tDepartment: " << dept << endl;
    }
  
  int update_roll(int r)
    {
        roll = r;
    }
    void update_name(string n)
    {
        name = n;
    }
    void update_dept(string dep)
    {
        dept = dep;
    }
    int get_roll()
    {
        return roll;
    }
    string get_name()
    {
        return name;
    }
    string get_dept()
    {
        return dept;
    }
};

int main()
{
    fstream database;
    
    vector<student> arr;
    int choice , x;
    string nam, dept;
    int roll, key;
    student temp;
    ifstream infile("Database.txt");
     if(infile.fail())
           {
               cout << "Error opening file" << endl;
           }
           else
           {
             while(infile>>nam)
             {
                 infile >> roll;
                 infile >> dept;
                 temp.set(nam, roll, dept);
                 arr.push_back(temp);
             }

           }

     
    do
    {
        cout << "\n\t.......Student Archive....." << endl;
        cout << "1.Input Information" << endl;
        cout << "2.Search Information " << endl;
        cout << "3.Update Info" << endl;
        cout << "4.Delete Info" << endl;
        cout << "5.Display All Info " << endl;
        cout << "6.Exit " << endl;
        cout << "Enter your choice :   ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "Enter Name" << endl;
            cin >> nam;
            cout << "Enter Roll" << endl;
            cin >> roll;
            cout << "Enter Department" << endl;
            cin >> dept;
            temp.set(nam, roll, dept);
            arr.push_back(temp);
            database.open("Database.txt", ios::out | ios::app);
            if (database.is_open())
            {
                database << temp.get_name() << endl;
                database << temp.get_roll() << endl;
                database << temp.get_dept() << endl;
                database.close();
            }
            break;
        case 2:
            cout << "Enter student's Roll" << endl;
            cin >> key;
            x = 0;
            for (int i = 0; i < arr.size(); i++)
            {
                if (arr[i].get_roll()==key)
                {
                    arr[i].displayinfo();
                    x = 1;
                }
               
            }
            if(x==0)
            {
                cout << "No Information with this roll Number" << endl;
            }

            break;

        case 3:
              cout << "Enter student's Roll to Update" << endl;
            cin >> key;
            x = 0;
            for (int i = 0; i < arr.size(); i++)
            {
                if (arr[i].get_roll()==key)
                {
                    cout << "1. Change Name" << endl;
                    cout << "2. Change Roll" << endl;
                    cout << "3. Change Department" << endl;

                    cout << "Enter Choice : ";
                    cin >> key;
                    switch (key)
                    {
                    case 1 :
                        cout << "Enter updated Name" << endl;
                        cin >> nam;
                        arr[i].update_name(nam);
                        break;
                     case 2 :
                        cout << "Enter updated Roll" << endl;
                        cin >> roll;
                        arr[i].update_roll(roll);
                        break;
                     case 3 :
                        cout << "Enter updated Department" << endl;
                        cin >> dept;
                        arr[i].update_dept(dept);
                        break;
                    }

                    cout << "Successfully Updated Information" << endl;
                    x = 1;
                }
               
            }
            if(x==0)
            {
                cout << "No Information with this roll Number" << endl;
            }

            break;
        case 4: 
            cout << "Enter student's Roll to delete" << endl;
            cin >> key;
            x = 0;
            for (int i = 0; i < arr.size(); i++)
            {
                if (arr[i].get_roll()==key)
                {

                    arr.erase(arr.begin() + i);
                    cout << "Successfully removed from Archive" << endl;
                    x = 1;
                }
               
            }
            if(x==0)
            {
                cout << "No Information with this roll Number" << endl;
            }

            break;

        case 5 : 
          cout << "      Displaying Information of " << arr.size();
                   cout<< "   Students :  ...."<< endl;
            for (int i = 0; i < arr.size(); i++)
            {
                arr[i].displayinfo();
            }

            break;

                }

    } while (choice != 6);

    return 0;

       }