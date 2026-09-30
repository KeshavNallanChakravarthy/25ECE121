#include <iostream>

inline int minVal(int a, int b) {
    return (a < b) ? a : b;
}


inline int minVal(int a, int b, int c) {
    return minVal(minVal(a, b), c);
}

int main() {
    std::cout << "Min of 10 and 20: " << minVal(10, 20) << "\n";
    std::cout << "Min of 30, 5, and 15: " << minVal(30, 5, 15) << "\n";
    return 0;
}
