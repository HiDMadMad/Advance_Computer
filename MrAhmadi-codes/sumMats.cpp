#include<iostream>
using namespace std;

int main()
{
    int rows = 2;
    int cols = 3;
    int Mat1[rows][cols] = {
    {1,2,3},
    {4,5,6}
    };
    int Mat2[rows][cols] = {
    {6,5,4},
    {3,2,1}
    };
    int res[rows][cols];

    for (int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            res[i][j] = Mat1[i][j] + Mat2[i][j];
        }
    }

    for (int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<res[i][j]<<"\t";
        }
        cout<<"\n";
    }



}
