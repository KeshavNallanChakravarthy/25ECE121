#include <iostream>
#include <fstream>
#include <climits>

void processNumberStats() {
    std::ifstream infile("nums.txt");
    if (!infile) {
        std::cerr << "Error: Could not open nums.txt for reading.\n";
        return;
    }

    int num;
    int count = 0;
    long long sum = 0;
    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    // Read an unknown count of integers until end-of-file
    while (infile >> num) {
        count++;
        sum += num;
        if (num < minVal) minVal = num;
        if (num > maxVal) maxVal = num;
    }
    infile.close();

    if (count == 0) {
        std::cout << "No integers found in nums.txt[cite: 5].\n";
        return;
    }

    std::cout << "=== 1. Number Stats from File ===\n";
    std::cout << "Count: " << count << "\n";
    std::cout << "Sum: " << sum << "\n";
    std::cout << "Min: " << minVal << "\n";
    std::cout << "Max: " << maxVal << "\n";
}
