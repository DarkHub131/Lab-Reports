/*
Write a program showing  2 options:
1. Create a New Account
2. Send Money from one account to another
*/

#include<iostream>
using namespace std;
class User
{
    string name;
    long long int phone;
    string address;
    string date_of_birth;
    long long int NID;
    string password;
    public:
        void NewAccount()
        {
            cout<< "Create a New Account\nEnter Name: ";
            cin>>name;
            cout<< "Enter Phone Number: ";
            cin>>phone;
            cout<< "Enter Address: ";
            cin>>address;
            cout<< "Enter Date Of Birth: ";
            cin>>date_of_birth;
            cout<< "Enter NID No.: ";
            cin>>NID;
            cout<< "Enter Password: ";
            cin>>password;
        }
        int Accno()
        {
            return phone;
        }
        string rpass()
        {
            return password;
        }
};

class Account
{
    double balance=1000;
public:
    User identity;
    void SendMoney(int n,double amount)
    {
        balance-=amount;
        cout<< "Taka "<<amount<< " Has been paid to Account Number "<<n<< ". Now, Your balance is "<<balance<<endl;
    }
    double getbal()
    {
        return balance;
    }
    double ReceiveMoney(double ramount)
    {
        balance+=ramount;
    }
};
int main()
{
    Account acc[10];
    int a, Sender, Receiver, NofAcc=0, i,j,c,d;
    string pass;
    double TransAmount;
    bool tf = true;
    while(true)
    {
        cout<< "1. Create a New Account\n2. Send Money\n3. Exit"<<endl;
        cin>>a;
        if(a==1)
        {
            acc[NofAcc].identity.NewAccount();
            NofAcc++;
            cout<< "Your Account has been created successfully."<<endl;
        }
        else if(a==2)
        {
            if(NofAcc==0)
            {
                cout << "Please an account first !" << endl;
            }
            else {
            cout<< "Enter Your Account Number: ";
            cin>>Sender;
            c=0;
            for(i=0;i<NofAcc;i++)
            {
                if(Sender==acc[i].identity.Accno())
                {
                    cout<< "Enter Password: ";
                    cin>>pass;
                    if(pass==acc[i].identity.rpass())
                    {
                        cout<< "Enter Receiver's Account Number: ";
                        cin>>Receiver;
                        d=0;
                        for(j=0;j<NofAcc;j++)
                        {
                            if(Receiver==acc[j].identity.Accno())
                            {
                                cout<< "Enter Amount: ";
                                cin>>TransAmount;
                                if(TransAmount<=acc[i].getbal())
                                {
                                    acc[i].SendMoney(Receiver,TransAmount);
                                    acc[j].ReceiveMoney(TransAmount);
                                }
                                else
                                {
                                    cout<< "Insufficient Balance"<<endl;
                                }
                                d=0;
                                break;
                            }
                            else
                                d=1;
                        }
                        if(d==1)
                            cout<< "Wrong Info ! There is no account with this ID"<<endl;
                    }
                    else
                        cout<< "Incorrect Password! Try again "<<endl;
                    c=0;
                    break;
                }
                else
                    c=1;
            }
            if(c==1)
         cout<< "Wrong Info ! There is no account with this ID"<<endl;
            }
        }

        else if(a==3)
            tf=false;
        else
            cout<< "invalid Choice"<<endl;
    }
    return 0;
};