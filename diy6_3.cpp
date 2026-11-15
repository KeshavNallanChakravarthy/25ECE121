#include <iostream>
#include <stdexcept> // for std::out_of_range

class SafeArray {
private:
    int* data;
    size_t size;

public:
    // Constructor
    explicit SafeArray(size_t s) : size(s) {
        data = new int[size]{}; // Initialize with zeros
    }

    // Destructor
    ~SafeArray() {
        delete[] data;
    }

    // Copy Constructor (Rule of Three)
    SafeArray(const SafeArray& other) : size(other.size) {
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Copy Assignment Operator
    SafeArray& operator=(const SafeArray& other) {
        if (this == &other) return *this;
        
        int* newData = new int[other.size];
        for (size_t i = 0; i < other.size; ++i) {
            newData[i] = other.data[i];
        }

        delete[] data;
        data = newData;
        size = other.size;
        return *this;
    }

    // Overload operator[] for non-const objects (allows writing)
    int& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("SafeArray error: Index out of range!");
        }
        return data[index];
    }

    // Overload operator[] for const objects (read-only)
    const int& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("SafeArray error: Index out of range!");
        }
        return data[index];
    }

    size_t getSize() const {
        return size;
    }
};
