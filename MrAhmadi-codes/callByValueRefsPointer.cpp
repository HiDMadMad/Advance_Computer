#include<iostream>
using namespace std;

void funcCallByValue(int a)
{
    a = a+10;
    cout <<"in function callByValue, a = "<<a<<endl;
    //return a;
}
void funcCallByReference(int &b)
{
    b = b + 10;
    cout <<"in function callByRef, b = "<<b<<endl;
}

void funcCallByPointer(int *c)
{
    *c = *c + 40;
}

int main()
{
    int a,b,z;
    a = 5;
    b=10;
    z = 25;
    cout<<"before function, a = "<<a<<endl;
    funcCallByValue(a);
    cout<<"after function, a = "<<a<<endl;
    cout<<"***********************************************"<<endl;
    cout<<"before function, b = "<<b<<endl;
    funcCallByReference(b);
    cout<<"after function, b = "<<b<<endl;
    //***********************************************
    cout<<"***********************************************"<<endl;
    //***********************************************
    cout<<"before function, z = "<<z<<endl;
    funcCallByPointer(&z);
    cout<<"after function, z = "<<z<<endl;
    //***********************************************
}
