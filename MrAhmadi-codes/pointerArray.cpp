
#include<iostream>
using namespace std;

int main()
{
    int N;
    float *grade=0;
    float *temp;
    float A=10;
    temp = &A;
    //cout<<*temp<<endl;

    cout<< "Enter the number of student"<<endl;
    cin>>N;
    temp = new float;
    *temp = 11;
    //cout<<*temp<<endl;
    //return 1;
    grade = new float[N];

    for(int i=0;i<N;i++)
        cin>>grade[i];

    float sum=0;
    for (int j=0;j<N;j++)
        sum += grade[j];


    float ave = sum/N;
    cout<<"ave= "<<ave<<endl;



    grade = &A;

    for (int j=0;j<N;j++)
        cout<<grade[j]<<"\t";

    delete[] grade;


    return 0;
}
