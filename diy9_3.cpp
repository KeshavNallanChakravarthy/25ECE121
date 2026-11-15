#include <iostream>
#include <exception>

// Base custom math error[cite: 4]
class MathError : public std::exception {
public:
    const char* what() const noexcept override {
        return "General Math Error occurred.";
    }
};

// Derived division by zero error[cite: 4]
class DivideByZero : public MathError {
public:
    const char* what() const noexcept override {
        return "Divide By Zero Error: Division denominator cannot be zero!";
    }
};
