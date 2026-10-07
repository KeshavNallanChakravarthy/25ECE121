#include <iostream>

class distance {
    int feet; //PVT
    int inches; //PVT

public:
    distance(int feet, int inches) : feet(feet), inches(inches) {}
    friend distance add(const distance &d1, const distance &d2);
    void show() { std::cout << feet << " feet, " << inches << " inches" << std::endl; }
};

distance add(const distance &d1, const distance &d2) {
    int totalFeet = d1.feet + d2.feet;
    int totalInches = d1.inches + d2.inches;
    if (totalInches >= 12) {
        totalFeet += totalInches / 12;
        totalInches %= 12;
    }
    return distance(totalFeet, totalInches);
}

int main() {
    distance d1 (5,8), d2(3,7);
    distance d3 = add(d1, d2);
    d3.show();
    return 0;
}