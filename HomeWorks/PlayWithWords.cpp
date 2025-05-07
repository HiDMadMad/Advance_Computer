#include <iostream>
#include <string>

int LenOfWord(std::string str)
{
    int Cnt{0}, CharsCnt{0};
    while(str[Cnt]!='\0')
    {
        if( (str[Cnt]>='A' && str[Cnt]<='Z') || (str[Cnt]>='a' && str[Cnt]<='z') )
            CharsCnt++;
        Cnt++;
    }
    return CharsCnt;
}

int NumOfWords1(std::string &str)
{
    bool IsChar {false};
    int StrCnt{0}, WordsCnt{0};
    while(str[StrCnt]!='\0')
    {
        if( !IsChar && ((str[StrCnt]>='a' && str[StrCnt]<='z') || (str[StrCnt]>='A' && str[StrCnt]<='Z')) )
        {
            IsChar = true;
            WordsCnt++;
        }
        else if( str[StrCnt]==' ' || str[StrCnt]=='\t' )
        {
            IsChar = false;
        }
        StrCnt++;
    }
    return WordsCnt;
}

int NumOfWords2(std::string &str)
{
    int StrCnt{0}, WordsCnt{0};
    while(str[StrCnt]!='\0')
    {
        if( ((str[StrCnt]>='A' && str[StrCnt]<='Z') || (str[StrCnt]>='a' && str[StrCnt]<='z')) && str[StrCnt-1]==' ' )
            WordsCnt++;
        StrCnt++;
    }
    if(str[0]==' ')
        return WordsCnt;
    else
        return WordsCnt+1;
}

void WordsSort(std::string str1="str1", std::string str2="str2", std::string str3="str3")
{
    int LowestLen, StrCnt{0}, WitchOne;
    if(str3!="str3")
    {
        // 3 words algo
        std::cout<<"not available yet..";
    /*
        int MaximumLen;
        if(LenOfWord(str1) > LenOfWord(str2) && LenOfWord(str1) > LenOfWord(str3))
            MaximumLen = LenOfWord(str1);
        else if (LenOfWord(str2) > LenOfWord(str1) && LenOfWord(str2) > LenOfWord(str3))
            MaximumLen = LenOfWord(str2);
        else if (LenOfWord(str3) > LenOfWord(str1) && LenOfWord(str3) > LenOfWord(str2))
            MaximumLen = LenOfWord(str3);
        else 
            MaximumLen = LenOfWord(str1);

        for(int i{0}; i<MaximumLen; i++)
        {

        }
    */
    }
    else
    {
        // 2 words algo
        while(str1[StrCnt]!='\0' && str2[StrCnt]!='\0')
        {
            if(str1[StrCnt] < str2[StrCnt])
            {
                std::cout<<str1<<'\t'<<str2;
                break;
            }
            else// else if(str1[StrCnt] < str2[StrCnt])
            {
                std::cout<<str2<<'\t'<<str1;
                break;
            }

        }
    }
}

int main()
{

    return 0;
}
//MadMad_100