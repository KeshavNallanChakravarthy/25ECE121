#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// Dynamic memory + copy constructor + copy-assignment operator (Programs 4.2, 4.3, 6.2, 6.3)
class Equipment {
private:
    int id;
    char* name;
    int x, y;
    int usageCount;
    static int nextId;
    static int aliveCount;

public:
    Equipment(const char* n = "Unnamed", int px = 0, int py = 0)
        : id(++nextId), x(px), y(py), usageCount(0) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        ++aliveCount;
        cout << "Created equipment #" << id << " (" << name << ")\n";
    }

    // Deep-copy constructor
    Equipment(const Equipment& other)
        : id(++nextId), x(other.x), y(other.y),
          usageCount(other.usageCount) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        ++aliveCount;
        cout << "Copied equipment into new object #" << id << "\n";
    }

    // Deep-copy assignment with self-assignment protection
    Equipment& operator=(const Equipment& other) {
        if (this != &other) {
            char* newName = new char[strlen(other.name) + 1];
            strcpy(newName, other.name);
            delete[] name;
            name = newName;
            x = other.x;
            y = other.y;
            usageCount = other.usageCount;
        }
        return *this;
    }

    ~Equipment() {
        cout << "Destroyed equipment #" << id << " (" << name << ")\n";
        delete[] name;
        --aliveCount;
    }

    void use() { ++usageCount; }
    void resetUsage() { usageCount = 0; }

    int getUsage() const { return usageCount; }
    int getId() const { return id; }
    const char* getName() const { return name; }

    // this pointer and method chaining (Program 3.3)
    Equipment& setX(int value) { this->x = value; return *this; }
    Equipment& setY(int value) { this->y = value; return *this; }

    void show() const {
        cout << "ID: " << id << " | " << name
             << " | Location: (" << x << ", " << y << ")"
             << " | Usage: " << usageCount << '\n';
    }

    // Static member function (Program 5.1)
    static int getAliveCount() { return aliveCount; }

    // Friend function (Program 5.2 concept)
    friend int totalUsage(const Equipment& a, const Equipment& b);

    // Operator overloading (Program 6.1)
    Equipment operator+(const Equipment& other) const {
        Equipment combined("Combined usage record");
        combined.usageCount = usageCount + other.usageCount;
        return combined;
    }

    bool operator==(const Equipment& other) const {
        return usageCount == other.usageCount;
    }

    friend ostream& operator<<(ostream& os, const Equipment& e) {
        os << e.name << " [ID " << e.id << ", usage " << e.usageCount << "]";
        return os;
    }
};

int Equipment::nextId = 0;
int Equipment::aliveCount = 0;

// Friend function can access private data
int totalUsage(const Equipment& a, const Equipment& b) {
    return a.usageCount + b.usageCount;
}

// Pass-by-reference functions (Program 3.3)
void relocateX(Equipment& e, int newX) { e.setX(newX); }
void relocateY(Equipment& e, int newY) { e.setY(newY); }

int main() {
    cout << "=== SMART LAB EQUIPMENT TRACKER ===\n\n";

    Equipment oscilloscope("Oscilloscope", 2, 3);
    Equipment signalGenerator("Signal Generator", 5, 1);

    // Lambda expression to display multiple objects (Program 3.2)
    auto display = [](const Equipment& a, const Equipment& b) {
        cout << "\n-- Current equipment --\n";
        a.show();
        b.show();
    };

    display(oscilloscope, signalGenerator);

    cout << "\n-- Recording equipment usage --\n";
    oscilloscope.use();
    oscilloscope.use();
    signalGenerator.use();
    signalGenerator.use();
    signalGenerator.use();
    display(oscilloscope, signalGenerator);

    cout << "\n-- Updating location using reference functions --\n";
    relocateX(oscilloscope, 10);
    relocateY(signalGenerator, 8);
    oscilloscope.setX(11).setY(12); // chained setters using this pointer
    display(oscilloscope, signalGenerator);

    cout << "\nTotal usage (friend function): "
         << totalUsage(oscilloscope, signalGenerator) << '\n';

    cout << "\nCombined record (operator+): "
         << (oscilloscope + signalGenerator) << '\n';

    cout << "Same usage count? "
         << (oscilloscope == signalGenerator ? "Yes" : "No") << '\n';

    // Copy constructor creates an independent deep copy
    Equipment backup = oscilloscope;
    cout << "Backup created: " << backup << '\n';

    // Assignment operator replaces the contents of an existing object
    Equipment spare("Spare Unit");
    spare = signalGenerator;
    cout << "Assigned spare: " << spare << '\n';

    cout << "\nLive objects before temporary scope ends: "
         << Equipment::getAliveCount() << '\n';

    {
        Equipment temporary("Temporary Meter");
        temporary.use();
        cout << "Inside block, live objects: "
             << Equipment::getAliveCount() << '\n';
    } // destructor called automatically here

    cout << "\nLive objects after block: "
         << Equipment::getAliveCount() << '\n';

    signalGenerator.resetUsage();
    cout << "\nAfter resetting signal generator usage:\n";
    signalGenerator.show();

    cout << "\n=== END OF TRACKER ===\n";
    return 0;
}
