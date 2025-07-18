#include<iostream>
using namespace std;

int fibona(int i);
int factorial(int p);

int main()
 {
     int N,next;
     double res,facti,fibi;
     cout<<"Enter N: ";
     cin>>N;

     res = 0;

     for (int i=1; i<=N; i++)
     {
         fibi = fibona(i);
         facti = factorial(i);
         res  += fibi/facti;
     }

     cout<< res;

    return 0;
 }



 int fibona(int i)
{
    int f1,f2,next;
    f1 = 1;
    f2 = 1;
    if (i==1)
        return f1;
    else if (i==2)
        return f2;
    else
    {
        for (int j=3;j<=i;j++)
        {
            next = f1 + f2;
            f1 = f2;
            f2 = next;
        }
        return next;
    }
}
//*****************************************
int factorial(int p)
{
    int res=1;
    for (int j = 1;j<=p;j++)
    {
        res*=j;
    }
    return res;
}
