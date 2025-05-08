#include<iostream>
using namespace std;

const int MAX=2;

class Student{

    private:
        string name;
        float score1;
        float score2;

    public:
        //string name;
        void input()
        {
            cout<<"Enter name: ";
            cin>> name;
            cout<<"Enter scores: ";
            cin>> score1>>score2;
        }
        float average()
        {
            return (score1+score2)/2.0;
        }
        void display()
        {
            cout<<name<<" ave = "<<average()<<endl;
        }

};

int main()
{

    Student stds[MAX];

    for(int i=0;i<MAX;i++)
    {
        stds[i].input();
        //stds[i].name;
    }

    for(int i=0;i<MAX;i++)
    {
        cout<<stds[i].name<<endl;
        //stds[i].display();
    }


    return 0;
}
