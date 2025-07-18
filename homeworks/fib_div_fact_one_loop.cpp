#include<iostream>

using namespace std;

int main()
{
    int N, FirstFib{1}, SecondFib{1};
    double Ans{0}, Fibi, Facti{1};

    cin>>N;

    for(int i=1; i<=N; i++)
    {
        Facti*=i;
        cout<<"\nFact "<<i<<" = "<<Facti<<endl;

        if(i==1 || i==2)
        {
            Fibi=1;
            cout<<"Fib "<<i<<" = "<<FirstFib<<"\n\n";
        }
        else
        {
            Fibi = FirstFib + SecondFib;
            FirstFib = SecondFib;
            SecondFib = Fibi;
            //cout<<"First :"<<FirstFib<<"\tSecond :"<<SecondFib<<"\tNext :"<<Fibi;
            cout<<"Fib "<<i<<" = "<<Fibi<<"\n\n";
        }


        Ans += (Fibi/Facti);
    }

    cout<<"\n\nAnswer is : "<<Ans<<"\n\n";

    return 0;
}
//MadMad_39
