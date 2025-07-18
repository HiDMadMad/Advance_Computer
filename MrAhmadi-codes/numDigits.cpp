#include<iostream>
using namespace std;

int main()
{

    int num, numDigs,temp, R;
    cout<<"Enter an integer number:";
    cin>>num;
    // 1234%10=4      (1-(1%10)/10
    numDigs = 0;

    temp = num;
    while (temp>0)
    {
        R = temp%10;//3
        numDigs ++;
        temp = (temp - R)/10;//123//12//1
    }

    cout<<"Number of digits = "<<numDigs;
    return 0;
}
