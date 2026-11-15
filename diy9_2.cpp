#include <iostream>
#include <exception>

// Custom exceptions for stack[cite: 4]
class Overflow : public std::exception {
public:
    const char* what() const noexcept override {
        return "Stack Overflow: Cannot push to a full stack!";
    }
};

class Underflow : public std::exception {
public:
    const char* what() const noexcept override {
        return "Stack Underflow: Cannot pop from an empty stack!";
    }
};

class Stack {
private:
    int* data;
    int top;
    int capacity;

public:
    explicit Stack(int size) : capacity(size), top(-1) {
        data = new int[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    void push(int value) {
        if (top >= capacity - 1) {
            throw Overflow();
        }
        data[++top] = value;
        std::cout << "Pushed " << value << " onto the stack.\n";
    }

    int pop() {
        if (top < 0) {
            throw Underflow();
        }
        return data[top--];
    }
};
