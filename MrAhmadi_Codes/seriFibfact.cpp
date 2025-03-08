#include<iostream>
using namespace std;

int main()
 {
     int N,next;
     double res,facti,fibi;
     cout<<"Enter N: ";
     cin>>N;

     res = 0;

     for (int i=1;i<=N;i++)
     {
         int f1=1;
         int f2=1;
         if (i==1)
            fibi = f1;
         else if (i==2)
            fibi=f2;
         else
         {
            for (int j=3;j<=i;j++)
            {
                next = f1 + f2;
                f1 = f2;
                f2 = next;
            }
            fibi = next;
         }
         //cout<<"fibi = "<<fibi<<endl;
         facti = 1;
         for(int k =1;k<=i;k++)
            facti *= k;
        //cout<<"facti = "<<facti<<endl;

         res += fibi/facti;

     }

     cout<< res;

    return 0;
 }
