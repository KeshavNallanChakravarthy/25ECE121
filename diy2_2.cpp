#include <iostream>
#include <cmath> // For std::pow


long long power(int base, int exp = 2) {
    return std::pow(base, exp);
}

int main() {
    // Testing the function
    std::cout << "power(5)    = " << power(5) << std::endl;     
    std::cout << "power(2, 10) = " << power(2, 10) << std::endl; 
    
    return 0;
}
