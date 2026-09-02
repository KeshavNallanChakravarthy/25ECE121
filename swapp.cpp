#include <iostream>
using namespace std;

int main() {
    int a=10; int b=20;
     cout<<"B4 SWAP "<<"a="<<a<<" b="<<b<<endl;
    swap(a,b);
     cout<<"AFTER SWAP "<<"a="<<a<<" b="<<b<<endl;
}

void swap(int x, int y) {
    int temp;
    temp = x;
    x=y;
    y = temp;
}

