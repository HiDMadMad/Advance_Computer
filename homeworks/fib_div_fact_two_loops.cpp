#include<iostream>

using namespace std;

int main()
{
    int N, FirstFib, SecondFib;
    double Ans{0}, Fibi, NextFib, Facti{1};

    cin>>N;

    for(int i=1; i<=N; i++)
    {
        Facti*=i;
        cout<<"\nFact "<<Facti<<endl;

        FirstFib=1;
        SecondFib=1;
        if(i==1 || i==2)
        {
            Fibi=FirstFib;
            cout<<"Fib "<<Fibi<<endl<<endl;
        }
        else
        {
            for(int j=3; j<=i; j++)
            {
                NextFib = FirstFib + SecondFib;
                FirstFib = SecondFib;
                SecondFib = NextFib;
                //cout<<"Fir "<<FirstFib<<"\tSec"<<SecondFib<<"\tNext"<<NextFib<<endl;
            }
            Fibi = NextFib;
            cout<<"Fib "<<Fibi<<endl<<endl;
        }

        Ans += (Fibi/Facti);
    }

    cout<<"\n\nAnswer is : "<<Ans<<"\n\n";

    return 0;
}
//MadMad_44
