#include <iostream>
#include <string>

class Counter {
private:
    std::string id;
    int count;

public:
    Counter(std::string name) : id(name), count(0) {}

    void increment() {
        count++;
    }

    void reset() {
        count = 0;
    }

    int get() const {
        return count;
    }

    std::string getId() const {
        return id;
    }
};

int main() {
    
    Counter counterA("Counter A");
    Counter counterB("Counter B");
    Counter counterC("Counter C");

    
    auto printStates = [](const Counter& a, const Counter& b, const Counter& c) {
        std::cout << a.getId() << ": " << a.get() << "\n";
        std::cout << b.getId() << ": " << b.get() << "\n";
        std::cout << c.getId() << ": " << c.get() << "\n";
    };

    
    std::cout << "--- Initial State ---\n";
    printStates(counterA, counterB, counterC);

    // Increment 
    counterA.increment();
    counterA.increment();

    counterB.increment();
    counterB.increment();
    counterB.increment();

    counterC.increment();

    std::cout << "\n--- After Increments ---\n";
    printStates(counterA, counterB, counterC);

    // Reset Counter B
    counterB.reset();

    std::cout << "\n--- After Resetting Counter B ---\n";
    printStates(counterA, counterB, counterC);

    return 0;
}
