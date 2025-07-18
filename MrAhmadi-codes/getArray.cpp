#include<iostream>
using namespace std;

int main()
{
    int N=3;
    int numArray[N];
    int temp;

    for(int i=0;i<N;i++)
    {
        cin>>temp;
        numArray[i] = temp;
    }

    for(int i=0;i<N;i++)
        cout<<numArray[i]<<"\t";

    return 0;
}
