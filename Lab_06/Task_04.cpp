#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear, size;
    int *arr;

public:
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % size == front);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int val = arr[front];
        if (front == rear) {
            front = rear = -1; 
        } else {
            front = (front + 1) % size;
        }
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
        int i = front;
        cout << "Queue: ";
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5);

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
