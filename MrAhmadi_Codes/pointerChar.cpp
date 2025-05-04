#include<iostream>
using namespace std;


int myStrLen(char *str)
{
    int counter=0;
    while(str[counter]!='\0')//while(str[counter++]!='\0');
        counter++;

    return counter;
}

int countA(char *str)
{
    int counter=0,cntA=0;
    while(str[counter]!='\0')
    {
        if (str[counter]=='a' || str[counter]=='A   ')
            cntA++;
        counter++;
    }


    return cntA;

}

int main()
{
    int N = 100;
    char ch;
    char str[N];

    //cin.get(ch);
    //cout<<ch;
    int i=0;
    while (cin.get(ch) && ch!='\n' && i<N)
        str[i++]=ch;
        //cin>>ch[i];
    str[i]='\0';
    cout<<str<<endl;
    cout<<myStrLen(str)<<endl;
    cout<<countA(str)<<endl;

    return 0;
}
