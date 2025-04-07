#include<iostream>
using namespace std;

int temp(int a)
{
    a = a+10;
    cout <<"in function, a = "<<a<<endl;
    return a;
}

int main()
{
    int a,b;
    a = 5;
    cout<<"before function, a = "<<a<<endl;
    b = temp(a);
    cout<<"after function, a = "<<a<<endl;
    cout<<"after function, b = "<<b<<endl;
}
