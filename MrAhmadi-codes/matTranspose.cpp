#include<iostream>
using namespace std;
/*
1 2 3
4 5 6
*/
/*
1 4
2 5
3 6
*/

int main()
{
    int rows = 2; int cols = 3;
    int M[rows][cols];
    int MT[cols][rows];
    int MT2[cols][rows];

    for (int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            cin>>M[i][j];

    for (int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            MT[j][i] = M[i][j];

    for (int i=0;i<cols;i++)
        for(int j=0;j<rows;j++)
            MT2[i][j] = M[j][i];

    for (int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<M[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"*********************"<<endl;
    for (int i=0;i<cols;i++)
    {
        for(int j=0;j<rows;j++)
        {
            cout<<MT2[i][j]<<"\t";
        }
        cout<<"\n";
    }



}
