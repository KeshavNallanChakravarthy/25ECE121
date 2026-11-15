#include <iostream>
#include <cmath>

class Money {
private:
    long rupees;
    int paise;

    // Helper to normalize paise into valid range [0, 99] and adjust rupees
    void normalize() {
        // Convert everything to total paise first to handle negative values uniformly
        long total_paise = rupees * 100 + paise;
        rupees = total_paise / 100;
        paise = total_paise % 100;
        
        if (paise < 0) {
            paise += 100;
            rupees -= 1;
        }
    }

public:
    Money(long r = 0, int p = 0) : rupees(r), paise(p) {
        normalize();
    }

    // Overload binary '+'
    Money operator+(const Money& other) const {
        return Money(rupees + other.rupees, paise + other.paise);
    }

    // Overload binary '-'
    Money operator-(const Money& other) const {
        return Money(rupees - other.rupees, paise - other.paise);
    }

    void display() const {
        std::cout << "Rs. " << rupees << "." << (paise < 10 ? "0" : "") << paise << std::endl;
    }
};
