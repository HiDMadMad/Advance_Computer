#include<iostream>
using namespace std;

int main()
{
    int N=4;
    int stdNo[N];
    int grade[N];

    for (int i=0;i<N;i++)
    {
        cin>> stdNo[i];
        cin>>grade[i];
    }

    for (int i=0;i<N;i++)
    {
        cout<<stdNo[i]<<"\t"<<grade[i]<<endl;
    }
}
