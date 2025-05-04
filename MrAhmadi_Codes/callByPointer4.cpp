#include<iostream>
using namespace std;


int main()
{
    float a,b,c;
    float *d,*e,*f;

    a = 10;
    d = &a;
    b = 5;
    cout <<"a= "<<a<<", *d= "<<*d<<endl;
    //d=0;
    d = &b;
    cout <<"a= "<<a<<", *d= "<<*d<<endl;

    cout<<"****************************"<<endl;
    cout <<"d = "<<d<<", *d = "<<*d<<endl;
    e = d;
    cout<<"****************************"<<endl;
    cout <<"d = "<<d<<", *d = "<<*d<<", e = "<<e<<", *e = "<<*e ;

    //e = &c; ---> *e = *d;
    //e = d;
    return 0;
}
