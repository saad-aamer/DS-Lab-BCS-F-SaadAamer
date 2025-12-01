#include <iostream>
using namespace std;

class LinearQueue {
private:
    int front, rear, size;
    int *arr;

public:
    LinearQueue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == size - 1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (front == -1) front = 0;
        rear++;
        arr[rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int val = arr[front];
        front++;
        if (front > rear) front = rear = -1;
        return val;
    }

    int peek() {
        if (!isEmpty()) return arr[front];
        cout << "Queue Empty!" << endl;
        return -1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue Empty!" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    LinearQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();

    q.enqueue(50);
    q.enqueue(60);
    q.display();

    cout << "Front Element: " << q.peek() << endl;

    return 0;
}
