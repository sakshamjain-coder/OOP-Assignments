#include <iostream>
using namespace std;

class Complex
{
    double real, imag;

public:
    Complex()
    {
        real = 0;
        imag = 0;
    }

    void setComplex(double r, double i)
    {
        real = r;
        imag = i;
    }

    void printComplex()
    {
        cout << real << " + " << imag << "i" << endl;
    }

    Complex operator+(Complex c)
    {
        Complex t;
        t.real = real + c.real;
        t.imag = imag + c.imag;
        return t;
    }

    Complex operator*(Complex c)
    {
        Complex t;
        t.real = real * c.real - imag * c.imag;
        t.imag = real * c.imag + imag * c.real;
        return t;
    }

    friend ostream& operator<<(ostream& out, const Complex& c)
    {
        out << c.real << " + " << c.imag << "i";
        return out;
    }

    friend istream& operator>>(istream& in, Complex& c)
    {
        in >> c.real >> c.imag;
        return in;
    }

    friend Complex& add(Complex& a, Complex& b)
    {
        static Complex result;
        result.real = a.real + b.real;
        result.imag = a.imag + b.imag;
        return result;
    }
};

int main()
{
    Complex c1, c2, c3, c4;

    cout << "Enter first complex number (real imaginary): ";
    cin >> c1;

    cout << "Enter second complex number (real imaginary): ";
    cin >> c2;

    c3 = c1 + c2;
    cout << "Addition: " << c3 << endl;

    c4 = c1 * c2;
    cout << "Multiplication: " << c4 << endl;

    Complex& result = add(c1, c2);
    cout << "Friend function addition: " << result << endl;

    return 0;
}