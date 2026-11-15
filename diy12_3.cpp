#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate

void customAggregateDemo() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};

    // Compute the product of all elements using a lambda[cite: 7]
    long long product = std::accumulate(nums.begin(), nums.end(), 1LL, [](long long acc, int val) {
        return acc * val;
    });

    // Compute the sum of only the even numbers using a lambda[cite: 7]
    int sumOfEvens = std::accumulate(nums.begin(), nums.end(), 0, [](int acc, int val) {
        return (val % 2 == 0) ? acc + val : acc;
    });

    std::cout << "=== 3. Custom Aggregate Test ===\n";
    std::cout << "Product of all elements: " << product << "\n";
    std::cout << "Sum of only the even numbers: " << sumOfEvens << "\n";
}
