#include<iostream>
using namespace std;
#include<string>

int main()
{

    string word1,word2;
    cout<<"enter first word: ";
    cin>>word1;
    cout<<"enter second word: ";
    cin>>word2;

    int ch=0;
    int res=0;

    while (word1[ch] != '\0' && word2[ch] != '\0')
    {
        if (word1[ch] <word2[ch])
        {
            res = 1;
            break;
        }
        else if (word1[ch] > word2[ch])
        {
            res = 2;
            break;
        }
        ch++;
    }

    if (res == 1)
    {
        cout << word1 <<"\t"<<word2<<endl;
    }
    else if (res==2)
    {
        cout << word2 <<"\t"<<word1<<endl;
    }
    else
    {
        if (word1[ch] == '\0' && word2[ch]=='\0')
        {
            cout << "=="<<endl;
        }
        else if (word1[ch]=='\0')
        {
            cout << word1 <<"\t"<<word2<<endl;
        }
        else{
            cout << word2 <<"\t"<<word1<<endl;
        }
    }

    //cout<<word1<<" "<<word2;
    return 0;
}
