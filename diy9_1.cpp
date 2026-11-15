#include <iostream>
#include <string>
#include <stdexcept>

// Custom exception for insufficient funds
class InsufficientFunds : public std::runtime_error {
public:
    explicit InsufficientFunds(const std::string& message) 
        : std::runtime_error(message) {}
};

class BankAccount {
private:
    double balance;

public:
    explicit BankAccount(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFunds("Error: Withdrawal amount exceeds current balance!");
        }
        balance -= amount;
        std::cout << "Successfully withdrew: Rs. " << amount << ". Remaining balance: Rs. " << balance << "\n";
    }

    double getBalance() const { return balance; }
};
