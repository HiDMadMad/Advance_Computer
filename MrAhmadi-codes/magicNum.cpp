#include<iostream>
using namespace std;

int main()
{
    //145 = 1! + 4! + 5!
    // get out the digits ---> evaluate factorial --- > if sum(facts)== num
    int num,temp, R, sumFactsDigs , fact , i;
    cout<<"Enter an integer number:";
    cin>>num;
    sumFactsDigs = 0;

    temp = num;
    while (temp>0)
    {
        R = temp%10;//3
        temp = (temp - R)/10;//123//12//1
        fact = 1;
        for (i=1;i<=R;i++)
            fact *= i;
        sumFactsDigs +=fact;
    }

    if (sumFactsDigs == num)
        cout<<"yes it is magic";
    else
        cout<<"no it is not magic";

    return 0;
}
