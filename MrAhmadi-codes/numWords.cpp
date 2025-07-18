#include<iostream>
using namespace std;
#include<string>

int main()
{
    string str;
    getline(cin,str);

    int ch=0;
    int numWords =0;
    bool flag=1;
    while (str[ch]!='\0')
    {
        if (flag && ((str[ch]>='a' && str[ch]<='z') || (str[ch]>='A' && str[ch]<='Z')))
        {
            flag = 0;
            numWords++;
        }
        else if ((str[ch] ==' ' || str[ch] == '\t' || str[ch]=='\n'))
        {
            flag=1;
        }
        ch++;
    }


    cout<<numWords<<endl;

    return 0;
}
