#include <iostream>
using namespace std;

class Tracer {
private:
    int id;

public:
    Tracer(int value) {
        id = value;
        cout << "Tracer " << id << " created\n";
    }

    ~Tracer() {
        cout << "Tracer " << id << " destroyed\n";
    }
};

int main() {
    cout << "Creating and deleting objects:\n";

    for (int i = 1; i <= 3; i++) {
        Tracer* ptr = new Tracer(i);

        delete ptr;
    }

    cout << "\nCreating objects without deleting them:\n";

    for (int i = 4; i <= 6; i++) {
        Tracer* ptr = new Tracer(i);

      
    }

    cout << "\nProgram ending\n";

    return 0;
}
