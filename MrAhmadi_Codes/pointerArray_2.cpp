#include<iostream>
using namespace std;

int main()
{

    int N = 5;
    int *arr;
    arr = new int[N];

    for (int i=0;i<N;i++)
        *(arr+i)=i;
        //arr[i]=i;


    for (int i=0;i<N;i++)
        cout<<*(arr+i)<<"\t";
        //cout<<arr[i]<<"\t";


}
