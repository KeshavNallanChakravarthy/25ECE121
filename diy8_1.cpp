#include <iostream>
#include <vector>

// 1. Abstract Account base class with pure-virtual calculateInterest()
class Account {
protected:
    double balance;

public:
    Account(double b) : balance(b) {}
    
    // Pure virtual function making this an abstract class
    virtual double calculateInterest() = 0;
    
    virtual double getBalance() const { return balance; }
    
    virtual ~Account() {} // Virtual destructor for safe polymorphism
};

// Derived Savings account with a higher interest rate (e.g., 5%)
class Savings : public Account {
private:
    double interestRate;

public:
    Savings(double b, double rate = 5.0) : Account(b), interestRate(rate) {}

    double calculateInterest() override {
        return balance * (interestRate / 100.0);
    }
};

// Derived Current account with a lower interest rate (e.g., 1%)
class Current : public Account {
private:
    double interestRate;

public:
    Current(double b, double rate = 1.0) : Account(b), interestRate(rate) {}

    double calculateInterest() override {
        return balance * (interestRate / 100.0);
    }
};
