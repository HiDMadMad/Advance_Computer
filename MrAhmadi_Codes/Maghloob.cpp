#include<iostream>
using namespace std;

int main()
{

    //1234
    //4321
    //3006,6003
    int num, revNum,temp, R;
    cout<<"Enter an integer number:";
    cin>>num;
    // 234,0*10+4 = 4,4*10+3=43,43*10+2=432
    revNum = 0;

    temp = num;
    while (temp>0)
    {
        R = temp%10;//3
        temp = (temp - R)/10;//123//12//1
        revNum = revNum*10 + R;
    }

    cout<<"Number of digits = "<<revNum;
    return 0;
}
