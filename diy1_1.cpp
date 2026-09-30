#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string s;
    int vowels = 0;
    int consonants = 0;

    cout << "Enter a sentence: ";
    getline(cin, s); 

    for (char ch : s) {
        char lowerCh = tolower(ch);
        
        
        if (isalpha(lowerCh)) {
            if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
