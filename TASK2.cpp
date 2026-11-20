#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <memory>
#include <stdexcept>
#include <algorithm>
using namespace std;

class InvalidMark : public exception {
    string msg;
public:
    InvalidMark(int m) : msg("Invalid mark: " + to_string(m)) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

class Person {
protected:
    string name;
public:
    Person(string n) : name(n) {}
    virtual void display() const = 0;
    virtual ~Person() {}
};

class Student : public Person {
    int roll;
public:
    Student(string n, int r) : Person(n), roll(r) {}
    int getRoll() const { return roll; }
    string getName() const { return name; }
    void display() const override { cout << roll << " - " << name; }
};

class Result : public Student {
    int marks;
public:
    Result(string n, int r, int m) : Student(n, r), marks(m) {
        if (m < 0 || m > 100) throw InvalidMark(m);
    }
    int getMarks() const { return marks; }
    void display() const override {
        Student::display();
        cout << " | Marks: " << marks << (marks >= 40 ? " [PASS]" : " [FAIL]") << '\n';
    }
};

template <typename T>
T maxVal(T a, T b) { return (a > b) ? a : b; }

int main() {
    ofstream out("results.csv");
    out << "101,Asha,91\n102,Ravi,35\n103,Meera,88\n104,Kiran,105\n";
    out.close();

    vector<unique_ptr<Result>> records;
    map<string, int> gradeCount;
    ifstream in("results.csv");
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string rStr, name, mStr;
        getline(ss, rStr, ','); getline(ss, name, ','); getline(ss, mStr, ',');
        try {
            auto rec = make_unique<Result>(name, stoi(rStr), stoi(mStr));
            gradeCount[rec->getMarks() >= 40 ? "Pass" : "Fail"]++;
            records.push_back(move(rec));
        } catch (const exception& e) {
            cerr << "[WARN] " << name << ": " << e.what() << '\n';
        }
    }

    int top = 0;
    auto showPassed = [&](const unique_ptr<Result>& r) {
        top = maxVal(top, r->getMarks());
        if (r->getMarks() >= 40) r->display();
    };
    cout << "--- Passed Students ---\n";
    for_each(records.begin(), records.end(), showPassed);
    cout << "Top Score: " << top << " | Pass: " << gradeCount["Pass"]
         << ", Fail: " << gradeCount["Fail"] << '\n';
    return 0;
}
