#include<iostream>
using namespace std;

// 6---->1,2,3,6
// N is complete?
int main()
{
    int N,i,sumDivs;
    cout<<"Enter N: ";
    cin>>N;

    sumDivs = 0;

    for(i=1;i<N;i++)
    {
        if (N%i == 0)
            sumDivs += i;
    }
    if (sumDivs == N)
        cout<< N << " is perfect!";
    else
        cout<<N << " is not perfect!";

    return 0;
}
