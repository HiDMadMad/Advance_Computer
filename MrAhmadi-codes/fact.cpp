#include<iostream>
using namespace std;

// N! = 1*2*...*N
int main()
{
    int N,i,res;
    cout<<"Enter N: ";
    cin>>N;

    res = 1;
    for (i=1;i<=N;i++)
    {
        res *= i; //res = res * i;
    }
    cout<<N<<"! = "<<res;

    return 0;
}
