#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

// Class template for a Generic Queue
template <typename T>
class Queue {
private:
    std::vector<T> elements;

public:
    // Enqueue an element to the back of the queue[cite: 6]
    void enqueue(const T& val) {
        elements.push_back(val);
    }

    // Dequeue an element from the front of the queue[cite: 6]
    void dequeue() {
        if (elements.empty()) {
            throw std::underflow_error("Queue underflow: Cannot dequeue from an empty queue.");
        }
        elements.erase(elements.begin());
    }

    // Get the front element of the queue[cite: 6]
    T front() const {
        if (elements.empty()) {
            throw std::underflow_error("Queue is empty: No front element.");
        }
        return elements.front();
    }

    bool empty() const {
        return elements.empty();
    }
};
