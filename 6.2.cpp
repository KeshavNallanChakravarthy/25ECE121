#include <iostream>
#include <cstring>
using namespace std;

class text {
    char *buf;
    public : text (const char *s = "") {
        buf = new char[strlen(s) + 1];
        strcpy(buf, s);
    }
    text (const text &t) {
        buf = new char[strlen(t.buf) + 1];
        strcpy(buf, t.buf);
    }
    text & operator=(const text &t) {
        if (this != &t) {
            delete[] buf;
            buf = new char[strlen(t.buf) + 1];
            strcpy(buf, t.buf);
        }
        return *this;
    }
    ~text() {
        delete[] buf;
    }
    void show () {
        cout << buf << endl;
    }
};

int main() {
    text a("alpha"), b("beta");
    b=a;
    a.show();
    b.show();
    return 0;
}