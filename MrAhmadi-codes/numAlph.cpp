#include<iostream>
using namespace std;


int main()
{
    char *str=new char[100];

    cin.getline(str,100);

    int capCount=0, smallCount=0, digCount=0, numWs=0;

    int ch=0;
    while (str[ch] != '\0' )
    {
        if (str[ch]>='a' && str[ch]<='z')
            smallCount++;
        else if (str[ch]>='A' && str[ch]<='Z')
            capCount++;
        else if (str[ch]>='0' && str[ch]<='9')
            digCount++;
        else if (str[ch]==' ' || str[ch]=='\t' || str[ch]=='\n')
            numWs++;
        ch++;
    }

    cout<<"numWs="<<numWs<<"\tnumSmall= "<<smallCount<<"\tnumCapt="<<capCount<<"\tnumDig="<<digCount<<endl;


    return 0;
}
