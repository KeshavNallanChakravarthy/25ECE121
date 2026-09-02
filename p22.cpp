#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string str;
    
    // Added missing quotation marks for the string literals
    cout << "ENTER STRING: " << endl;
    
    // Note: cin >> str only reads a single word. 
    // To read an entire line with spaces, use: getline(cin, str);
    cin >> str; 
    
    cout << "ENTERED STRING: " << str << endl;
    cout << "Length of string: " << str.length() << endl;
    
    cout << "Upper: ";
    for (char c : str) {
        cout << (char)toupper(c);
    }
    cout << endl;
    
    // Palindrome check logic
    bool pal = true;
    size_t i = 0, j = str.size() - 1;
    
    for (i = 0, j = str.size() - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            pal = false;
            break;
        }
    }
    
    // Fixed the ternary operator syntax and spacing
    cout << str << (pal ? " is " : " is not ") << "palindrome" << endl;
    
    return 0;
}
