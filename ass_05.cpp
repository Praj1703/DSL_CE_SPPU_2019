#include <iostream>


using namespace std;

class Stack {
public:
    static const int SIZE = 100;
    char a[SIZE];
    int tos;

    Stack() : tos(-1) {}

    void push(char c);
    void pop();
    void display() const;
    bool palindrome() const;
};

void Stack::push(char c) {
    if (tos < SIZE - 1) {
        a[++tos] = c;
    } else {
        cout << "Stack is full" << endl;
    }
}

void Stack::pop() {
    if (tos >= 0) {
        tos--;
    } else {
        cout << "Stack is empty" << endl;
    }
}

void Stack::display() const {
    if (tos >= 0) {
        cout << "Stack elements: ";
        for (int i = 0; i <= tos; ++i) {
            cout << a[i] << ' ';
        }
        cout << endl;
    } else {
        cout << "Stack is empty" << endl;
    }
}

bool Stack::palindrome() const {
    int i = 0, j = tos;
    while (i < j) {
        if (a[i] != a[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    Stack stack;
    char str[50];
    
    cout << "Enter the string to check for palindrome: ";
    cin.getline(str, 50);

    for (int i = 0; str[i] != '\0'; i++) {
        stack.push(str[i]);
    }

    stack.display();

    if (stack.palindrome()) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}

