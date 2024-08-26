#include <iostream>
using namespace std;

class Stack {
public:
    static const int SIZE = 2; 
    char a[SIZE];
    int tos;

    Stack() {
        tos = -1;
    }

    void push(char c);
    void pop();
    void display();
};

void Stack::push(char c) {
    if (tos == SIZE - 1) {
        cout << "Stack is full" << endl;
    } else {
        tos++;
        a[tos] = c;
    }
}

void Stack::pop() {
    if (tos == -1) {
        cout << "Stack is empty" << endl;
    } else {
        tos--;
    }
}

void Stack::display() {
    if (tos == -1) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack elements: ";
        for (int i = 0; i <= tos; ++i) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
}

int main() {
    Stack stack;

    stack.push('A');
    stack.push('B');
    stack.push('C');

    stack.display();

    stack.pop();
    stack.display();

    return 0;
}

