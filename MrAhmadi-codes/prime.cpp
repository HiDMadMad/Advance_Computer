#include<iostream>
using namespace std;

// N is prime?
int main()
{
    int N,i,numDiv;
    cout<<"Enter N: ";
    cin>>N;

    numDiv = 0;

    for(i=1;i<=N;i++)
    {
        if (N%i == 0)
            numDiv++;
    }
    if (numDiv == 2)
        cout<< N << " is prime";
    else
        cout<<N << " is not prime";

    return 0;
}
