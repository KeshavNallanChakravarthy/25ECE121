#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;

public:
    // Constructor
    Time(int h = 0, int m = 0) {
        hours = h + m / 60;
        minutes = m % 60;
    }

   
    friend Time laterOf(Time t1, Time t2);

    
    void display() const {
        cout << hours << ":";

        if (minutes < 10) {
            cout << "0";
        }

        cout << minutes << endl;
    }
};


Time laterOf(Time t1, Time t2) {
    int totalMinutes1 = t1.hours * 60 + t1.minutes;
    int totalMinutes2 = t2.hours * 60 + t2.minutes;

    if (totalMinutes1 >= totalMinutes2) {
        return t1;
    }

    return t2;
}

int main() {
    Time t1(10, 30);
    Time t2(14, 45);

    cout << "First time: ";
    t1.display();

    cout << "Second time: ";
    t2.display();

    Time later = laterOf(t1, t2);

    cout << "Later time: ";
    later.display();

    return 0;
}
