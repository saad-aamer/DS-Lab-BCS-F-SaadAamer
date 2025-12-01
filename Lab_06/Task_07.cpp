#include <iostream>
using namespace std;

struct Process {
    int id;
    int priority;
};

class ProcessQueue {
private:
    int front, rear, size;
    Process *arr;

public:
    ProcessQueue(int n) {
        size = n;
        arr = new Process[size];
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    bool isFull() {
        return rear == size - 1;
    }

    void enqueue(Process p) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        if (front == -1) front = 0;
        rear++;
        arr[rear] = p;
    }

    Process dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return {-1, -1};
        }
        Process p = arr[front];
        front++;
        if (front > rear) front = rear = -1;
        return p;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue Empty!\n";
            return;
        }
        cout << "Process Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << "[ID:" << arr[i].id << ",P:" << arr[i].priority << "] ";
        }
        cout << endl;
    }
};

class ProcessStack {
private:
    int top;
    int size;
    Process *arr;

public:
    ProcessStack(int n) {
        size = n;
        arr = new Process[size];
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void push(Process p) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = p;
    }

    Process pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return {-1, -1};
        }
        return arr[top--];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack Empty!\n";
            return;
        }
        cout << "Execution Stack (LIFO): ";
        for (int i = top; i >= 0; i--) {
            cout << "[ID:" << arr[i].id << ",P:" << arr[i].priority << "] ";
        }
        cout << endl;
    }
};


class JobScheduler {
private:
    ProcessQueue arrivalQueue;
    ProcessStack executionStack;

public:
    JobScheduler(int n) : arrivalQueue(n), executionStack(n) {}

    void addProcess(int id, int priority) {
        Process p = {id, priority};
        arrivalQueue.enqueue(p);
    }

    void schedule() {
        cout << "\nScheduling processes...\n";
        while (!arrivalQueue.isEmpty()) {
            Process p = arrivalQueue.dequeue();
            executionStack.push(p);
        }
    }

    void execute() {
        cout << "\nExecuting processes in LIFO order:\n";
        while (!executionStack.isEmpty()) {
            Process p = executionStack.pop();
            cout << "Executing Process ID: " << p.id << ", Priority: " << p.priority << endl;
        }
    }

    void displayQueue() { arrivalQueue.display(); }
    void displayStack() { executionStack.display(); }
};

int main() {
    JobScheduler scheduler(10);

    scheduler.addProcess(101, 2);
    scheduler.addProcess(102, 5);
    scheduler.addProcess(103, 1);
    scheduler.addProcess(104, 3);

    cout << "Initial Arrival Queue:\n";
    scheduler.displayQueue();

    scheduler.schedule();

    cout << "\nStack after scheduling:\n";
    scheduler.displayStack();

    scheduler.execute();

    return 0;
}
