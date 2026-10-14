#include <iostream>
using namespace std;

class Complex {
    double re, im;
public:
    Complex(double r = 0, double i = 0) : re(r), im(i) {}
    Complex operator+(const Complex& c) {
        return Complex(re + c.re, im + c.im);
    }
    bool operator ==(const Complex& c) {
        return (re == c.re && im == c.im);
    }
    friend ostream & operator<<(ostream &os, const Complex& c) {
        os << c.re << (c.im >= 0 ? "+" : "") << c.im << "i";
        return os;
    }
};

int main () {
    Complex a(2,3), b(1,-4);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a == b: " << (a == b ? "true" : "false") << endl;
    return 0;
}