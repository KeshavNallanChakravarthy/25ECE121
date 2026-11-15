#include <iostream>
#include <vector>
#include <queue>

void topThreeHeapDemo() {
    std::vector<int> numbers = {15, 3, 9, 22, 45, 12, 8, 30};
    
    // Use a min-heap to efficiently track the top 3 largest elements[cite: 7]
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (int num : numbers) {
        minHeap.push(num);
        if (minHeap.size() > 3) {
            minHeap.pop(); // Keep only the 3 largest elements
        }
    }

    std::cout << "=== 2. Top-3 with Heap Test ===\n";
    std::cout << "The 3 largest numbers are: ";
    
    std::vector<int> topThree;
    while (!minHeap.empty()) {
        topThree.push_back(minHeap.top());
        minHeap.pop();
    }
    
    // Print from largest to smallest
    for (auto it = topThree.rbegin(); it != topThree.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";
}
