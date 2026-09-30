#include <iostream>
#include <string>


void customReverse(std::string &s, int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

void reverseWords(std::string &s) {
    int n = s.length();
    
    
    customReverse(s, 0, n - 1);

    int start = 0;
   
    for (int end = 0; end <= n; ++end) {
        
        if (end == n || s[end] == ' ') {
            customReverse(s, start, end - 1);
            start = end + 1; 
        }
    }
}

int main() {
    std::string sentence = "hello world cpp";
    
    reverseWords(sentence);
    
    std::cout << sentence << std::endl; // Output: cpp world hello
    return 0;
}
