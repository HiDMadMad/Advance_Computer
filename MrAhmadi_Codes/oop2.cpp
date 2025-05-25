#include<iostream>

using namespace std;

int main()
{
    double height, width;

    cin>> height>>width;

    cout<<"area = " <<height * width<<endl;
    cout<<"Perimeter = " << 2 * (height + width)<<endl;

    
    return 0;
}