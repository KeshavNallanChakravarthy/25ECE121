#include <iostream>
using namespace std;

class Order {
private:
    static int nextID;
    int orderID;

public:
    // Constructor
    Order() {
        orderID = nextID++;

        cout << "Order created with ID: "
             << orderID << endl;
    }

    
    void display() const {
        cout << "Order ID: " << orderID << endl;
    }
};


int Order::nextID = 1001;

int main() {
    Order o1;
    Order o2;
    Order o3;

    cout << "\nDisplaying order IDs:\n";

    o1.display();
    o2.display();
    o3.display();

    cout << "\nCreating more orders:\n";

    Order o4;
    Order o5;

    return 0;
}
