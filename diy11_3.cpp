#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

void runFrequencyCounter() {
    // Sample input text containing repeated words[cite: 6]
    std::string input = "apple banana apple orange banana apple grape banana banana";
    std::stringstream ss(input);
    std::string word;

    // Use an unordered_map to track word frequencies[cite: 6]
    std::unordered_map<std::string, int> wordCountMap;

    while (ss >> word) {
        wordCountMap[word]++;
    }

    std::string mostFrequentWord = "";
    int maxFrequency = 0;

    std::cout << "Word Frequencies:\n";
    // Print each word with its count[cite: 6]
    for (const auto& pair : wordCountMap) {
        std::cout << pair.first << ": " << pair.second << "\n";
        
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
            mostFrequentWord = pair.first;
        }
    }

    // Print the most frequent word[cite: 6]
    std::cout << "\nMost frequent word: \"" << mostFrequentWord 
              << "\" with a count of " << maxFrequency << ".\n";
}
