#include <iostream>

// --- THE BUGGY VERSION ---
class BuggyBase {
public:
    ~BuggyBase() { // Non-virtual destructor!
        std::cout << "BuggyBase destructor called.\n";
    }
};

class BuggyDerived : public BuggyBase {
private:
    int* data; // Dynamically allocated memory[cite: 3]
public:
    BuggyDerived() {
        data = new int[100]; 
    }
    ~BuggyDerived() {
        delete[] data;
        std::cout << "BuggyDerived destructor called (This will NEVER run in the bug case!).\n";
    }
};

// --- THE FIXED VERSION ---
class Base {
public:
    virtual ~Base() { // Fixed: Virtual destructor ensures derived destructor is called
        std::cout << "Base virtual destructor called.\n";
    }
};

class Derived : public Base {
private:
    int* data;
public:
    Derived() {
        data = new int[100]; 
    }
    ~Derived() override {
        delete[] data;
        std::cout << "Derived destructor called correctly, memory freed!\n";
    }
};
