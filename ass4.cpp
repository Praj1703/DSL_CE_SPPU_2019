#include <iostream>
using namespace std;

#define SIZE 10

class stackexp {
    int top;
    char stk[SIZE];
public:
    stackexp() : top(-1) {} // Initialize top to -1

    void push(char);
    char pop();
    int isfull();
    int isempty();
};

void stackexp::push(char x) {
    if (isfull()) {
        cout << "Stack overflow!" << endl;
        return;
    }
    stk[++top] = x;
}

char stackexp::pop() {
    if (isempty()) {
        cout << "Stack underflow!" << endl;
        return '\0'; // Return null character for empty stack
    }
    return stk[top--];
}

int stackexp::isfull() {
    return top == SIZE - 1;
}

int stackexp::isempty() {
    return top == -1;
}

int main() {
    stackexp s1;
    char exp[100]; // Increased size to accommodate longer expressions
    int i = 0;
    cout << "\n\t!! Parenthesis Checker !!" << endl;
    cout << "\nEnter the expression to check whether it is well-formed or not: " << endl;
    cin >> exp;

    if ((exp[0] == ')') || (exp[0] == ']') || (exp[0] == '}')) {
        cout << "\nInvalid Expression .......\n";
        return 0;
    } else {
        while (exp[i] != '\0') {
            char ch = exp[i];
            switch (ch) {
                case '(':
                case '[':
                case '{':
                    s1.push(ch);
                    break;
                case ')':
                    if (s1.isempty() || s1.pop() != '(') {
                        cout << "\nSorry! The Expression is not well-parameterized....\n";
                        return 0;
                    }
                    break;
                case ']':
                    if (s1.isempty() || s1.pop() != '[') {
                        cout << "\nSorry! The Expression is not well-parameterized....\n";
                        return 0;
                    }
                    break;
                case '}':
                    if (s1.isempty() || s1.pop() != '{') {
                        cout << "\nSorry! The Expression is not well-parameterized....\n";
                        return 0;
                    }
                    break;
                default:
                    cout << "\nInvalid Character in Expression.\n";
                    return 0;
            }
            i++;
        }
    }

    if (s1.isempty()) {
        cout << "\nThe expression is well-parameterized.\n";
    } else {
        cout << "\nSorry! The expression is not well-parameterized.\n";
    }

    return 0;
}

