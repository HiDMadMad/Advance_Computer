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
        BankAccount(std::string OwNm, int pass, double InitialBalance, double RemainBalance, int AccountNum) : OwnerName(OwNm), password(pass), balance(InitialBalance), limit(RemainBalance), AccountNumber(AccountNum) {}
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
            
            int GetBalance(int BalancePass)
            {
                if(password == BalancePass)
                    return balance;
                else 
                    return -1;
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
        
            void withraw(int pass, double BalanceToWithraw)
            {
                if(pass == password)
                {
                    if(BalanceToWithraw>0 && balance>=(BalanceToWithraw-limit))
                    {
                        balance-=BalanceToWithraw;
                        std::cout<<"withraw is successful!\n";
                    }
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
                    ToAccount.deposit(TransferValue);
                    std::cout<<"transfer successful!\n";
                }
            }
    //------------------------------------------------------------------------------
};

class SavingAccount : public BankAccount
{

};


bool NameOrNum(int choice)
{
    if(choice == 1)
        return true; // owner name
    else
        return false; // account number
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


int main()
{
    BankAccount Accounts[MAX_ACCOUNTS];
    int AccountCounter{0}, InitialAccountNum{1001}, option;
    do
    {
        std::cout<<"\n\nwhat do you want to do ?\n1-create new account\n2-show accounts\n3-show account info\n4-deposit\n5-withraw\n6-transfer\n7-show balance\n0-quit\nyour choice : ";
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
                if(NameOrNum(DepositPath))
                {
                    std::cout<<"\nenter target owner name : ";
                    std::getline(std::cin>>std::ws, TargetAccountName);
                    for(int i=0; i<AccountCounter; i++)
                {
                    if(Accounts[i].GetAccountOwnerName() == TargetAccountName)
                    {
                        Accounts[i].ShowInfo();
                        break;
                    }
                }
                }
                else if(!NameOrNum(DepositPath))
                {
                    std::cout<<"\nenter target account number : ";
                    std::cin>>TargetAccountNum;
                    for(int i=0; i<AccountCounter; i++)
                {
                    if(Accounts[i].GetAccountNumber() == TargetAccountNum)
                    {
                        Accounts[i].ShowInfo();
                        break;
                    }
                }
                }
                break;
            }
            case 4: // deposit
            {
                double DepositValue{0};
                int DepositPath{0};
                std::cout<<"\ndo you have :\n1-account owner name\n2-account number\n";
                std::cin>>DepositPath;
                if(NameOrNum(DepositPath)) // by name
                {
                    std::string TargetAccountName;
                    std::cout<<"\nenter target owner name : ";
                    std::getline(std::cin>>std::ws, TargetAccountName);
                    std::cout<<"how much do you want to deposit : ";
                    std::cin>>DepositValue;
                    Accounts[FindIndexByName(Accounts, MAX_ACCOUNTS, TargetAccountName)].deposit(DepositValue);
                }
                else if(!NameOrNum(DepositPath)) // by number
                {
                    int  TargetAccountNum;
                    std::cout<<"\nenter target account number : ";
                    std::cin>>TargetAccountNum;
                    std::cout<<"how much do you want to deposit : ";
                    std::cin>>DepositValue;
                    Accounts[FindIndexByNum(Accounts, MAX_ACCOUNTS, TargetAccountNum)].deposit(DepositValue);
                }
                break;
            }
            case 5: // withraw
            {
                double WithrawValue{0};
                int AccountPassword, WithrawPath{0};
                std::cout<<"\ndo you have :\n1-account owner name\n2-account number\n";
                std::cin>>WithrawPath;
                if(NameOrNum(WithrawPath)) // by name
                {
                    std::string TargetAccountName;
                    std::cout<<"\nenter target owner name : ";
                    std::getline(std::cin>>std::ws, TargetAccountName);
                    std::cout<<"how much do you want to withraw : ";
                    std::cin>>WithrawValue;
                    std::cout<<"enter account password : ";
                    std::cin>>AccountPassword;
                    Accounts[FindIndexByName(Accounts, MAX_ACCOUNTS, TargetAccountName)].withraw(AccountPassword, WithrawValue);
                }
                else if(!NameOrNum(WithrawPath)) // by number
                {
                    int TargetAccountNum;
                    std::cout<<"\nenter target account number : ";
                    std::cin>>TargetAccountNum;
                    std::cout<<"how much do you want to withraw : ";
                    std::cin>>WithrawValue;
                    std::cout<<"enter account password : ";
                    std::cin>>AccountPassword;
                    Accounts[FindIndexByNum(Accounts, MAX_ACCOUNTS, TargetAccountNum)].withraw(AccountPassword, WithrawValue);
                }
                break;
            }
            case 6: // transfer
            {
                int ShowPath, Acc1PassWord;
                double value;
                std::cout<<"\ndo you have :\n1-accounts owners names\n2-accounts numbers\n";
                std::cin>>ShowPath;
                if(NameOrNum(ShowPath)) // by name
                {
                    std::string Acc1OwName, Acc2OwName;
                    std::cout<<"from account owner name : ";
                    std::getline(std::cin>>std::ws, Acc1OwName);
                    std::cout<<"to account owner name : ";
                    std::getline(std::cin>>std::ws, Acc2OwName);
                    std::cout<<"how much do you want to transfer : ";
                    std::cin>>value;
                    std::cout<<"enter your password : ";
                    std::cin>>Acc1PassWord;
                    Accounts[FindIndexByName(Accounts, MAX_ACCOUNTS, Acc1OwName)].TransferTo(Accounts[FindIndexByName(Accounts, MAX_ACCOUNTS, Acc2OwName)], Acc1PassWord, value);
                }
                else if(!NameOrNum(ShowPath)) // by num
                {
                    int Acc1Num, Acc2Num;
                    std::cout<<"from account number : ";
                    std::cin>>Acc1Num;
                    std::cout<<"to account number : ";
                    std::cin>>Acc2Num;
                    std::cout<<"how much do you want to transfer : ";
                    std::cin>>value;
                    std::cout<<"enter your password : ";
                    std::cin>>Acc1PassWord;
                    Accounts[FindIndexByNum(Accounts, MAX_ACCOUNTS, Acc1Num)].TransferTo(Accounts[FindIndexByNum(Accounts, MAX_ACCOUNTS, Acc2Num)], Acc1PassWord, value);
                        
                }
                break;
            }
            case 7:
            {
                std::string TargetAccountName;
                int AccountPassword, ShowPath{0}, TargetAccountNum;
                std::cout<<"\ndo you have :\n1-account owner name\n2-account number\n";
                std::cin>>ShowPath;
                if(NameOrNum(ShowPath))
                {
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
                else if(!NameOrNum(ShowPath))
                {
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
                break;
            }
            default :
            {
                std::cout<<"wtf";
                break;
            }
        }
    }while(option!=0);

    return 0;
}
//MadMad_372