#include<iostream>
using namespace std;

int main()
{
    int N=5,temp;
    int num[N];

    for (int i=0;i<N;i++)
    {
        cin>>temp;
        num[i] = temp;
    }
    for(int i=0;i<N;i++)
        cout<<num[i]<<"\t";

    return 0;
}
