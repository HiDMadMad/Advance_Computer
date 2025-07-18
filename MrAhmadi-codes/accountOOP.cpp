#include<iostream>
using namespace std;


class BankingAccount{
    private:
        string AccountHolder;
        int accNo;
        double balance;

    public:
    BankingAccount(string name, int accno, double firstBalance)
    {
        AccountHolder = name;
        accNo = accno;
        balance = firstBalance;
    }
    void deposit(double x)
    {
        if (x>0)
            balance += x;
    }
    void withdraw(double x)
    {
        if (x>0 && (x<=balance))
        {
            balance -= x;
        }
    }
    double getBalance()
    {
        return balance;
    }
    void displayInfo()
    {
        cout<<AccountHolder<<endl;
        cout<<accNo<<endl;
        cout<<balance<<endl;
    }

};

class SavingAccount: public BankingAccount{
    private:
        int InterestRate;
    public:
    SavingAccount(string name, int accNOOOO,double balance, int intRate): 
    BankingAccount(name,accNOOOO,balance){

        InterestRate = intRate;

    }
    void applyInterest()
    {
        double interest = getBalance() * InterestRate/100;
        deposit(interest);
    }
    
};

int main()
{
    /*BankingAccount acc1("Ali",11111,100000);
    acc1.displayInfo();
    acc1.deposit(150000);
    cout<<"********************"<<endl;
    acc1.displayInfo();
    cout<<"********************"<<endl;
    acc1.withdraw(50000);
    acc1.displayInfo();*/

    SavingAccount acc2("Melika",22222,150000,5);
    acc2.displayInfo();

    acc2.applyInterest();
    acc2.displayInfo();

    return 0;
}