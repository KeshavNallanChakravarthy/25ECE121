#include <iostream>
#include <string>
#include <cctype>

bool isAnagramCount(const std::string& word1, const std::string& word2) {
    int charCounts[26] = {0}; // Assuming lowercase English alphabets only
    int length1 = 0, length2 = 0;

    
    for (char ch : word1) {
        if (!std::isspace(ch)) {
            charCounts[std::tolower(ch) - 'a']++;
            length1++;
        }
    }

    
    for (char ch : word2) {
        if (!std::isspace(ch)) {
            charCounts[std::tolower(ch) - 'a']--;
            length2++;
        }
    }

    // If actual letter lengths don't match, they aren't anagrams
    if (length1 != length2) return false;

    // If any count is not zero, they aren't anagrams
    for (int count : charCounts) {
        if (count != 0) return false;
    }

    return true;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << isAnagramCount("Listen", "Silent") << std::endl;      // True
    std::cout << isAnagramCount("Debit Card", "Bad Credit") << std::endl; // True
    std::cout << isAnagramCount("Apple", "Pale") << std::endl;         // False
    return 0;
}