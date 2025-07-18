#include <iostream>
#include <string>

const int MAX_ACCOUNTS = 100; 

class BankAccount
{
    private :
        std::string OwnerName;
        int AccountNumber, password;
        double balance{0}, limit{0};
    public :
        BankAccount() =  default;  // برای استفاده نکردن از ارایه پوینتری
        BankAccount(std::string OwNm, int pass, double InitialBalance, double RemainBalance, int AccountNum) : OwnerName(OwNm), password(pass), balance(InitialBalance), AccountNumber(AccountNum) {}
        // {
        //     OwnerName = OwNm;
        //     password = pass;
        //     balance = InitialBalance;
        //     AccountNumber = AccountNum;
        // }
    //------------------------------------------------------------------------------
        // Info :
            void ShowInfo()
            {
                std::cout<<"\naccount number : "<<AccountNumber<<"\naccount owner : "<<OwnerName<<"\naccount balance : "<<balance<<'\n';
            }

            std::string GetAccountOwnerName()
            {
                return OwnerName;
            }

            int GetAccountNumber()
            {
                return AccountNumber;
            }
            
            double GetBalance(int BalancePass)
            {
                if(password == BalancePass)
                    return balance;
                else 
                {
                    std::cout<<"Wrong password!\n";
                    return -1;
                }
            }
    //------------------------------------------------------------------------------
        // Password :
            void ChangePassword(int PreviousPassword, int NewPass)
            {
                if(PreviousPassword == password)
                {    
                    password = NewPass;
                    std::cout<<"your password changed successfully\n";
                }
                else
                    std::cout<<"your pervious password is wrong!\n";
            }
    //------------------------------------------------------------------------------
        // Finance :
            void deposit(double NewBalance)
            {
                if(NewBalance>0)
                {
                    balance+=NewBalance;
                    std::cout<<"deposit is successful!\n";
                }
            }
            
            void TransferDeposit(double  NewBalance)
            {
                if(NewBalance>0)
                {
                    balance+=NewBalance;
                }
            }
            void withraw(int pass, double BalanceToWithraw)
            {
                if(pass == password)
                {
                    if(BalanceToWithraw>0 && balance>=BalanceToWithraw)
                    {
                        balance-=BalanceToWithraw;
                        std::cout<<"withraw is successful!\n";
                    }
                    else if(BalanceToWithraw<0)
                        std::cout<<"your request must be bigger than 0!";
                    else 
                        std::cout<<"your balance is not enough!\n";
                }
                else
                    std::cout<<"your password is wrong!\n";
            }

            void TransferTo(BankAccount &ToAccount, int TransferPassword, double TransferValue)
            {    
                if(TransferValue<=0)
                {
                    std::cout<<"value must be bigger than 0!\n";
                }
                else if(TransferValue > balance)
                {
                    std::cout<<"your balance is not enough!\n";
                }
                else if(TransferPassword != password)
                {
                    std::cout<<"your password is wrong!\n";
                }
                else
                {
                    balance-=TransferValue;
                    ToAccount.TransferDeposit (TransferValue);
                    std::cout<<"transfer successful!\n";
                }
            }
    //------------------------------------------------------------------------------
};

class SavingAccount : public BankAccount
{
    // private:
    //     SavingAccount
};


int NameOrNum(int choice)
{
    if(choice == 1)
        return 1; // owner name
    else if(choice == 2)
        return 0; // account number
    else
        return -1; // out of range
}

int FindIndexByNum(BankAccount BankAccs[], int NumOfBankAccs, int TargetNum)
{
    for(int i=0; i<NumOfBankAccs; i++)
    {
        if(BankAccs[i].GetAccountNumber() == TargetNum)
            return i;
    }
    return -1;
}

int FindIndexByName(BankAccount BankAccs[], int NumOfBankAccs, std::string TargetName)
{
    for(int i=0; i<NumOfBankAccs; i++)
    {
        if(BankAccs[i].GetAccountOwnerName() == TargetName)
            return i;
    }
    return -1;
}

void PrintMenu()
{
    // std::cout<<"\n\nwhat do you want to do ?\n1-create new account\n2-show accounts\n3-show account info\n4-deposit\n5-withraw\n6-transfer\n7-show balance\n0-quit\nyour choice : ";
    std::cout<<"\n\nwhat do you want to do ?"
    <<"\n1-create new account"
    <<"\n2-show accounts"
    <<"\n3-show account info"
    <<"\n4-deposit"
    <<"\n5-withraw"
    <<"\n6-transfer"
    <<"\n7-show balance"
    <<"\n0-quit"
    <<"\nyour choice : ";
}


int main()
{
    BankAccount Accounts[MAX_ACCOUNTS];
    int AccountCounter{0}, InitialAccountNum{1001}, option;
    do
    {
        PrintMenu();
        std::cin>>option;
        switch(option)
        {
            case 1:
            {
                if(AccountCounter<MAX_ACCOUNTS)
                {
                    std::string Name;
                    int PassWord, IsRepetitive{0};
                    double InitialBalance;
                    std::cout<<"\nenter your name : ";
                    std::getline(std::cin>>std::ws, Name);
                    for(int i=0; i<AccountCounter; i++)
                    {
                        //IsRepetitive=0;
                        if(Name == Accounts[i].GetAccountOwnerName())
                        {
                            IsRepetitive=1;
                            break;
                        }
                    }
                    if(IsRepetitive==0)
                    {
                        std::cout<<"enter your password : ";
                        std::cin>>PassWord;
                        std::cout<<"enter your initial balance : ";
                        std::cin>>InitialBalance;
                        Accounts[AccountCounter] = BankAccount(Name, PassWord, InitialBalance, 100, InitialAccountNum+AccountCounter);
                        AccountCounter++;
                        std::cout<<"your account created successfully!\n";
                    }
                    else
                    {
                        std::cout<<"this name has been taken!\n";
                    } 
                }
                else
                    std::cout<<"you can't create more accounts!\n";
                break;
            }
            case 2:
            {
                for(int i=0; i<AccountCounter; i++)
                {
                    Accounts[i].ShowInfo();
                }
                break;
            }
            case 3:
            {
                std::string TargetAccountName;
                double DepositValue{0};
                int DepositPath{0}, TargetAccountNum;  
                std::cout<<"\ndo you have :\n1-account owner name\n2-account number\n";
                std::cin>>DepositPath;
                if(NameOrNum(DepositPath)==1)
                {
                    std::cout<<"\nenter target owner name : ";
                    std::getline(std::cin>>std::ws, TargetAccountName);
                    Accounts[FindIndexByName(Accounts, AccountCounter, TargetAccountName)].ShowInfo();
                }
                else if(NameOrNum(DepositPath)==0)
                {
                    std::cout<<"\nenter target account number : ";
                    std::cin>>TargetAccountNum;
                    Accounts[FindIndexByNum(Accounts, AccountCounter, TargetAccountNum)].ShowInfo();
                }
                else
                    std::cout<<"out of range..!\n";
                break;
            }
            case 4: // deposit
            {
                double DepositValue{0};
                int DepositPath{0};
                std::cout<<"\ndo you have :\n1-account owner name\n2-account number\n";
                std::cin>>DepositPath;
                if(NameOrNum(DepositPath)==1) // by name
                {
                    std::string TargetAccountName;
                    std::cout<<"\nenter target owner name : ";
                    std::getline(std::cin>>std::ws, TargetAccountName);
                    if(FindIndexByName(Accounts, AccountCounter, TargetAccountName) != -1)
                    {
                        std::cout<<"how much do you want to deposit : ";
                        std::cin>>DepositValue;    
                        Accounts[FindIndexByName(Accounts, AccountCounter, TargetAccountName)].deposit(DepositValue);
                    }
                    else
                        std::cout<<"account was not found!\n";
                }
                else if(NameOrNum(DepositPath)==0) // by number
                {
                    int  TargetAccountNum;
                    std::cout<<"\nenter target account number : ";
                    std::cin>>TargetAccountNum;
                    if(FindIndexByNum(Accounts, AccountCounter, TargetAccountNum) != -1)
                    {
                        std::cout<<"how much do you want to deposit : ";
                        std::cin>>DepositValue;
                        Accounts[FindIndexByNum(Accounts, AccountCounter, TargetAccountNum)].deposit(DepositValue);
                    }
                    else
                        std::cout<<"account was not found!\n";
                }
                else
                    std::cout<<"out of range..!\n";
                break;
            }
            case 5: // withraw
            {
                double WithrawValue{0};
                int AccountPassword, WithrawPath{0};
                std::cout<<"\ndo you have :\n1-account owner name\n2-account number\n";
                std::cin>>WithrawPath;
                if(NameOrNum(WithrawPath)==1) // by name
                {
                    std::string TargetAccountName;
                    std::cout<<"\nenter target owner name : ";
                    std::getline(std::cin>>std::ws, TargetAccountName);
                    if(FindIndexByName(Accounts, AccountCounter, TargetAccountName) != -1)
                    {
                        std::cout<<"how much do you want to withraw : ";
                        std::cin>>WithrawValue;
                        std::cout<<"enter account password : ";
                        std::cin>>AccountPassword;
                        Accounts[FindIndexByName(Accounts, AccountCounter, TargetAccountName)].withraw(AccountPassword, WithrawValue);
                    }
                    else
                        std::cout<<"account was not found!\n";
                }
                else if(NameOrNum(WithrawPath)==0) // by number
                {
                    int TargetAccountNum;
                    std::cout<<"\nenter target account number : ";
                    std::cin>>TargetAccountNum;
                    if(FindIndexByNum(Accounts, AccountCounter, TargetAccountNum) != -1)
                    {
                        std::cout<<"how much do you want to withraw : ";
                        std::cin>>WithrawValue;
                        std::cout<<"enter account password : ";
                        std::cin>>AccountPassword;
                        Accounts[FindIndexByNum(Accounts, AccountCounter, TargetAccountNum)].withraw(AccountPassword, WithrawValue);
                    }
                    else
                        std::cout<<"account was not found!\n";
                }
                else
                    std::cout<<"out of range..!\n";
                break;
            }
            case 6: // transfer
            {
                int TransferPath, Acc1PassWord;
                double value;
                std::cout<<"\ndo you have :\n1-accounts owners names\n2-accounts numbers\n";
                std::cin>>TransferPath;
                if(NameOrNum(TransferPath)==1) // by name
                {
                    std::string Acc1OwName, Acc2OwName;
                    std::cout<<"from account owner name : ";
                    std::getline(std::cin>>std::ws, Acc1OwName);
                    if(FindIndexByName(Accounts, AccountCounter, Acc1OwName) != -1)
                    {
                        std::cout<<"to account owner name : ";
                        std::getline(std::cin>>std::ws, Acc2OwName);
                        if(FindIndexByName(Accounts, AccountCounter, Acc2OwName) != -1)
                        {
                            std::cout<<"how much do you want to transfer : ";
                            std::cin>>value;
                            std::cout<<"enter your password : ";
                            std::cin>>Acc1PassWord;
                            Accounts[FindIndexByName(Accounts, AccountCounter, Acc1OwName)].TransferTo(Accounts[FindIndexByName(Accounts, AccountCounter, Acc2OwName)], Acc1PassWord, value);
                        }
                        else 
                            std::cout<<"receiver account was not found!\n";
                    }
                    else
                        std::cout<<"sender account was not found!\n";
                }
                else if(NameOrNum(TransferPath)==0) // by num
                {
                    int Acc1Num, Acc2Num;
                    std::cout<<"from account number : ";
                    std::cin>>Acc1Num;
                    if(FindIndexByNum(Accounts, AccountCounter, Acc1Num) != -1)
                    {
                        std::cout<<"to account number : ";
                        std::cin>>Acc2Num;
                        if(FindIndexByNum(Accounts, AccountCounter, Acc2Num) != -1)
                        {
                            std::cout<<"how much do you want to transfer : ";
                            std::cin>>value;
                            std::cout<<"enter your password : ";
                            std::cin>>Acc1PassWord;
                            Accounts[FindIndexByNum(Accounts, AccountCounter, Acc1Num)].TransferTo(Accounts[FindIndexByNum(Accounts, AccountCounter, Acc2Num)], Acc1PassWord, value);
                        }
                        else 
                            std::cout<<"receiver account was not found!\n";
                    }
                    else 
                        std::cout<<"receiver account was not found!\n";
                }
                else
                    std::cout<<"out of range..!\n";
                break;
            }
            case 7: // show balance
            {
                
                int AccountPassword, ShowPath{0};
                std::cout<<"\ndo you have :\n1-account owner name\n2-account number\n";
                std::cin>>ShowPath;
                if(NameOrNum(ShowPath)==1) // by name
                {
                    std::string TargetAccountName;
                    std::cout<<"\nenter target owner name : ";
                    std::getline(std::cin>>std::ws, TargetAccountName);
                    std::cout<<"enter account password : ";
                    std::cin>>AccountPassword;
                    for(int i=0; i<AccountCounter; i++)
                    {
                        if(Accounts[i].GetAccountOwnerName() == TargetAccountName)
                        {
                            std::cout<<Accounts[i].GetBalance(AccountPassword);
                            break;
                        }
                    }
                }
                else if(NameOrNum(ShowPath)==0) // by num
                {
                    int TargetAccountNum;
                    std::cout<<"\nenter target account number : ";
                    std::cin>>TargetAccountNum;
                    std::cout<<"enter account password : ";
                    std::cin>>AccountPassword;
                    for(int i=0; i<AccountCounter; i++)
                    {
                        if(Accounts[i].GetAccountNumber() == TargetAccountNum)
                        {
                            std::cout<<Accounts[i].GetBalance(AccountPassword);
                            break;
                        }
                    }
                }
                else
                    std::cout<<"out of range..!\n";
                break;
            }
            default :
            {
                std::cout<<"Invalid option! Please try again.\n";
                break;
            }
        }
    }while(option!=0);

    return 0;
}
//MadMad_439