#include<iostream>
using namespace std;

const int MAX=2;

int main()
{

    string names[MAX];
    float score1[MAX];
    float score2[MAX];

    for (int i=0; i<MAX; i++)
    {
        cout<< "Enter name: ";
        cin>> names[i];

        cout<< "Enter grades: ";
        cin>> score1[i]>>score2[i];
    }
    for (int i=0; i<MAX;i++)
    {
        cout<<names[i]<<" ave = ";
        cout<<(score1[i]+score2[i])/2.0 <<endl;
    }

    return 0;
}
