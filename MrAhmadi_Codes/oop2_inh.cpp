#include<iostream>

using namespace std;

class Shape{
    private:
        string name;
    public:
    Shape(string str)
    {
        name = str;
    }
    void displayName()
    {
        cout<< "shape is " << name << endl;
    }

};

class Rectangle: public Shape{
    private:
        double height;
        double width;
    public:
    Rectangle(double h,double w): Shape("Rectangle")
    {
            height = h;
            width = w;
    }
    double area()
    {
        return height * width;
    }
    double perimeter()
    {
        return 2 * (height + width);
    }
    void display()
    {
        displayName();
        cout<< "height = " << height <<", width = "<<width<<endl;
        cout<<"area = " << area()<<endl;
        cout <<"perimiter = "<<perimeter()<<endl;
    }

};

int main()
{
    //Shape r("Rectangle");
    //Shape t("Triangle");

    Rectangle rect(6,8);
    rect.display();

    return 0;
}
