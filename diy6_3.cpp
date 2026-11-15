#include <iostream>
#include <numeric> // for std::gcd

class Fraction {
private:
    long num;
    long den;

    void simplify() {
        if (den == 0) {
            std::cerr << "Error: Denominator cannot be zero. Setting to 1.\n";
            den = 1;
            num = 0;
            return;
        }
        // Find greatest common divisor
        long common = std::gcd(num, den);
        num /= common;
        den /= common;

        // Ensure denominator is always positive
        if (den < 0) {
            num = -num;
            den = -den;
        }
    }

public:
    Fraction(long n = 0, long d = 1) : num(n), den(d) {
        simplify();
    }

    // Overload stream insertion (<<)
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f) {
        out << f.num;
        if (f.den != 1) {
            out << "/" << f.den;
        }
        return out;
    }

    // Overload stream extraction (>>)
    friend std::istream& operator>>(std::istream& in, Fraction& f) {
        char slash;
        in >> f.num >> slash >> f.den;
        f.simplify();
        return in;
    }
};
