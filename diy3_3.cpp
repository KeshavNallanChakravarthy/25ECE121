#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
   
    Complex() : real(0.0), imag(0.0) {}

    // Data for complex number
    void setData(double r, double i) {
        real = r;
        imag = i;
    }

    //(a + bi)
    void display() const {
        if (imag >= 0) {
            std::cout << real << " + " << imag << "i";
        } else {
            // Handles negative imaginary numbers smoothly without printing "+ -"
            std::cout << real << " - " << -imag << "i";
        }
    }
};

int main() {
    // Size of the array
    const int SIZE = 3;
    Complex numberArray[SIZE];

    // Assignment
    numberArray[0].setData(3.5, 4.5);
    numberArray[1].setData(1.2, -2.8);
    numberArray[2].setData(-5.0, 0.0);

    // To Display 
    std::cout << "--- Complex Numbers Array ---" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        std::cout << "Number " << (i + 1) << ": ";
        numberArray[i].display();
        std::cout << std::endl;
    }

    return 0;
}
