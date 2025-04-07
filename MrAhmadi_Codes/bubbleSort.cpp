#include<iostream>
using namespace std;

int main()
{
    int N=5;
    int numArray[N];
    int temp;

    for(int i=0;i<N;i++)
    {
        cin>>temp;
        numArray[i] = temp;
    }

    for (int i=0;i<N;i++)
    {
        for(int j=0;j<N-i;j++)
        {
            if (numArray[j] > numArray[j+1])
            {
                temp = numArray[j];
                numArray[j] = numArray[j+1];
                numArray[j+1] = temp;
            }
        }
    }

    for(int i=0;i<N;i++)
        cout<<numArray[i]<<"\t";

    return 0;
}
