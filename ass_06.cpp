#include <iostream>

#define MAX 100

using namespace std;

class Queue {
private:
    int arr[MAX];
    int front;
    int rear;
    int size;

public:
    Queue() : front(0), rear(-1), size(0) {}

    void enqueue(int value) {
        if (size == MAX) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = value;
        size++;
    }

    void dequeue() {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front = (front + 1) % MAX;
        size--;
    }

    void display() const {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; ++i) {
            cout << arr[(front + i) % MAX] << " ";
        }
        cout << endl;
    }

    int getSize() const {
        return size;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue size: " << q.getSize() << endl;
    q.display();

    q.dequeue();
    q.dequeue();

    cout << "Queue size: " << q.getSize() << endl;
    q.display();

    q.enqueue(40);
    q.enqueue(50);

    cout << "Queue size: " << q.getSize() << endl;
    q.display();

    return 0;
}

