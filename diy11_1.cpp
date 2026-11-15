#include <iostream>
#include <stdexcept>

// Template function to swap two values
template <typename T>
void swapVals(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Template function to find the maximum element in an array
template <typename T>
T findMax(T arr[], int n) {
    if (n <= 0) {
        throw std::invalid_argument("Array size must be greater than zero.");
    }
    T maxVal = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}
