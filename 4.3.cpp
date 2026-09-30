#include <iostream>
using namespace std;

class box {
    int w, h, d;
    public: 
        box(int w, int h, int d) : w(w), h(h), d(d) {}
        box() : box(1, 1, 1) {}
        box(int s) : box (s, s, s) {}
        int volume() const {return w*h*d;} 
};

int main (){
    box a;
    box b(3);
    box c(2,3,4);
    cout << a.volume() << " " << b.volume() << " " << c.volume() << " " ;
    return 0;
}
