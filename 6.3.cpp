#include <iostream>
using namespace std;

class count{
    
    int c;
    public:
    count(int i=0):c(i){}
    count operator++(){
        ++c;
        return *this;
    }
    count operator++(int){
        count temp = *this;
        ++c;
        return temp;
    }
    int value() const{
        return c;
    }
};

class safearr {
    int a[5] = {10,20,30,40,50};
    public:
    int & operator[](int i){
        if(i<0 || i>=5){
            cout << "Index out of bounds" << endl;
            exit(1);
        }
        return a[i];
    }
};

int main (){
    count c(5);
    ++c;
    c++;
    safearr s;
    cout << "s[2] = " << s[2] << s[2]<<endl;
    s[10] =99;
    return 0;
}

  