#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string str;

    cout << "ENTER STRING: ";
    cin >> str;

    cout << "ENTERED STRING: " << str << endl;
    cout << "Length of string: " << str.length() << endl;

    cout << "Upper: ";
    for (char c : str)
        cout << (char)toupper(c);
    cout << endl;

    bool pal = true;

    if (!str.empty())
    {
        for (size_t i = 0, j = str.size() - 1; i < j; i++, j--)
        {
            if (str[i] != str[j])
            {
                pal = false;
                break;
            }
        }
    }

    cout << str << (pal ? " is " : " is not ")
         << "palindrome" << endl;

    return 0;
}