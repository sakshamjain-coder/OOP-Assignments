#include <iostream>
using namespace std;

class Shapes
{
public:
    double area(double r)
    {
        return 3.14 * r * r;
    }

    double area(int s)
    {
        return s * s;
    }

    double area(double l, double b)
    {
        return l * b;
    }

    Shapes()
    {
        cout << "Default Constructor Called" << endl;
    }

    Shapes(double r)
    {
        cout << "Circle Area: " << area(r) << endl;
    }

    Shapes(int s)
    {
        cout << "Square Area: " << area(s) << endl;
    }

    Shapes(double l, double b)
    {
        cout << "Rectangle Area: " << area(l, b) << endl;
    }
};

int main()
{
    Shapes s1;
    Shapes s2(5.0);
    Shapes s3(4);
    Shapes s4(6.0, 3.0);

    return 0;
}