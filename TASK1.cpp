#include <iostream>
#include <cstring>
using namespace std;

class Book {
    int pagesRead, totalPages;
    char* title;
    static int activeBooks;
    char* copyStr(const char* s) { return strcpy(new char[strlen(s) + 1], s); }
public:
    Book(const char* t = "Untitled", int total = 100)
        : pagesRead(0), totalPages(total), title(copyStr(t)) { ++activeBooks; }
    Book(const Book& o)
        : pagesRead(o.pagesRead), totalPages(o.totalPages), title(copyStr(o.title)) { ++activeBooks; }
    Book& operator=(const Book& o) {
        if (this != &o) { delete[] title; title = copyStr(o.title); pagesRead = o.pagesRead; totalPages = o.totalPages; }
        return *this;
    }
    ~Book() { delete[] title; --activeBooks; }
    Book& read(int p) { this->pagesRead = min(totalPages, pagesRead + p); return *this; }
    Book operator+(const Book& o) const {
        Book sum("Combined", totalPages + o.totalPages);
        sum.pagesRead = pagesRead + o.pagesRead;
        return sum;
    }
    friend int remainingPages(const Book& b);
    friend ostream& operator<<(ostream& os, const Book& b) {
        return os << b.title << " (" << b.pagesRead << "/" << b.totalPages << ")";
    }
    static int getActiveBooks() { return activeBooks; }
};

int Book::activeBooks = 0;
int remainingPages(const Book& b) { return b.totalPages - b.pagesRead; }
void markFinished(Book& b) { b.read(remainingPages(b)); }

int main() {
    Book b1("C++ Primer", 300), b2("Algorithms", 200);
    auto show = [](const Book& b) { cout << b << " | Left: " << remainingPages(b) << '\n'; };

    b1.read(50).read(70);
    markFinished(b2);
    show(b1); show(b2);

    Book b3 = b1;          // copy constructor (deep copy)
    b2 = b3;               // copy assignment operator
    cout << "Combined: " << (b1 + b2) << '\n';
    cout << "Active books: " << Book::getActiveBooks() << '\n';
    return 0;
}
