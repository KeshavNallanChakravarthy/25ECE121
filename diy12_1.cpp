#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void sortPairsDemo() {
    std::vector<std::pair<std::string, int>> vec = {
        {"Alice", 85},
        {"Bob", 92},
        {"Charlie", 78},
        {"Diana", 95}
    };

    // Sort by the integer (second) field ascending
    std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    std::cout << "=== 1. Sort Pairs Test ===\n";
    std::cout << "Sorted pairs by integer field (ascending):\n";
    for (const auto& p : vec) {
        std::cout << "{" << p.first << ", " << p.second << "} ";
    }
    std::cout << "\n\n";
}
