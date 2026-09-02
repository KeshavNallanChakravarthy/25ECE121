#include<iostream>  

#include<string>
#include<cctype>
using namespace std;
int main()
{
    string str;
    cout<< "ENTER STRING"<< endl;
    cin>>str;
    cout<<"ENTERD STRING"<<str<<endl;
    cout<<"length of string: "<<str.length()<<endl;
    cout<<"Upper: ";
    for (char c: str)
        cout<<(char)toupper(c);
        cout<<endl;
        
    bool pal=true;
    size_t i=0, j=str.size()-1;
    
   for (i = 0, j = str.size() - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            pal = false;
            break;
        }break;
    }
    
   cout << str << (pal ? " is " : " is not ") << "palindrome" << endl;
    return 0;
}
































































