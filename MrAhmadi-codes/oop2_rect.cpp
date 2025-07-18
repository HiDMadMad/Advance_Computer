#include<iostream>

using namespace std;

class Rectangle
{
    private:
        double height;
        double width;
    public:
        Rectangle(double h=1,double w=1)
        {
            height = h;
            width = w;
        }
        void setHeight(double h)
        {
            height = h;
        }
        void setWidth(double w)
        {
            width = w;
        }
        void display()
        {
            cout<<"height = "<<height<<" width = "<<width<<endl;
            cout<<"area = "<<area()<<endl;
            cout<<"perimeter = "<<perimeter()<<endl;
        }
        double area()
        {
            return height * width;
        }
        double perimeter()
        {
            return 2*(height + width);
        }
};

int main()
{
 
    Rectangle rect(10,5);
    Rectangle ttt(3,6);
    Rectangle x3;
    x3.display();
    x3.setHeight(2);
    x3.setWidth(6);
    x3.display();
    
    //rect.display();
    //ttt.display();

}