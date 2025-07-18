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
        for(int j=i+1;j<N-1;j++)
        {
            if (numArray[i] > numArray[j])
            {
                temp = numArray[i];
                numArray[i] = numArray[j];
                numArray[j] = temp;
            }
        }
    }

    for(int i=0;i<N;i++)
        cout<<numArray[i]<<"\t";

    return 0;
}
