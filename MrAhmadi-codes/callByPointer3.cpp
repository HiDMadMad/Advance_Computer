#include<iostream>
using namespace std;


int change(float *f, float *g, float *k)
{
    *k = *f + *g;

    //f=0;
    //g=0;
    if (*k>100)
        return 1;
    else
        return 0;
}

int main()
{
    float a,b,c;
    int d;

    a = 10.1;
    b = 20.1;
    c = 0;
    d = change(&a,&b,&c);
    cout<<"a= "<<a<<", b= "<<b<<", c = "<<c<<", d = "<<d<<endl;


    return 0;
}
