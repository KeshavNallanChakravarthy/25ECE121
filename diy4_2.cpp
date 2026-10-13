#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int capacity;
    int top;

public:
    //constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;

        cout << "Stack created with capacity "
             << capacity << endl;
    }

    //push an element
    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }

        arr[++top] = value;

        cout << value << " pushed into stack\n";
    }

    //pop an element
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }

        cout << arr[top--] << " popped from stack\n";
    }

    //display stack
    void display() const {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack elements (top to bottom):\n";

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }

    //destructor
    ~Stack() {
        delete[] arr;

        cout << "Stack memory released\n";
    }
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.pop();

    s.display();

    return 0;
}
