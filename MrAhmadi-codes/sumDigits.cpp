#include<iostream>
using namespace std;

int main()
{

    int num, sumDigs,temp, R;
    cout<<"Enter an integer number:";
    cin>>num;
    // 1234%10=4      (1-(1%10)/10
    sumDigs = 0;

    temp = num;
    while (temp>0)
    {
        R = temp%10;//3
        sumDigs += R;
        temp = (temp - R)/10;//123//12//1
    }

    cout<<"Sum of digits = "<<sumDigs;
    return 0;
}
