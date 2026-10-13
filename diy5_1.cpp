#include <iostream>
using namespace std;

class Counter {
private:
    static int totalCreated;
    static int currentlyAlive;

public:
    // Constructor
    Counter() {
        totalCreated++;
        currentlyAlive++;

        cout << "Object created\n";
    }

    // Destructor
    ~Counter() {
        currentlyAlive--;

        cout << "Object destroyed\n";
    }

    static void displayStats() {
        cout << "Total objects created: "
             << totalCreated << endl;

        cout << "Currently alive: "
             << currentlyAlive << endl;
    }
};


int Counter::totalCreated = 0;
int Counter::currentlyAlive = 0;

int main() {
    Counter::displayStats();

    cout << "\nCreating objects:\n";

    Counter c1;
    Counter c2;

    Counter::displayStats();

    {
        cout << "\nEntering inner scope:\n";

        Counter c3;
        Counter c4;

        Counter::displayStats();

        cout << "\nLeaving inner scope:\n";
    }

    Counter::displayStats();

    cout << "\nCreating another object:\n";

    Counter c5;

    Counter::displayStats();

    return 0;
}
