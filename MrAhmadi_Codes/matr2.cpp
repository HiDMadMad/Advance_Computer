#include<iostream>
using namespace std;
/*
1 5 8
6 2 9
*/
// A[0][0]
int main()
{
    int nRow=4;
    int nCol =2;
    float stdSpecs[nRow][nCol];
    float ave;

    for (int i=0;i<nRow;i++)
    {
        cout<<"Enter stdNo ";
        cin>> stdSpecs[i][0];
        cout<<"Enter grade ";
        cin>>stdSpecs[i][1];
    }

    for (int i=0;i<nRow;i++)
    {
        cout<<stdSpecs[i][0]<<"\t"<<stdSpecs[i][1]<<endl;
    }

    for(int j=0;j<nRow;j++)
        ave += stdSpecs[j][1];
    ave = ave/nRow;
    cout<<"average = "<<ave;
}
