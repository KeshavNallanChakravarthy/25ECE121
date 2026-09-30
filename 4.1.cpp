#include <iostream>
using namespace std;

class tracer {
    int id;
    public: 
        tracer(int i) : id(i){cout<<"construct #"<<id<<endl;}
        ~tracer() {cout<<"destruct #"<<id<<endl;}
};

int main() {
    cout << "enter block \n";
    tracer a(1), b(2);
    cout<<"..working..";
    return 0;
}