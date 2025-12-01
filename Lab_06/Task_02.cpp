#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;
public:
    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return (top == NULL);
    }

    void push(int value) {
        Node* temp = new Node(value);
        temp->next = top;
        top = temp;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int x = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return x;
    }

    int peek() {
        if (!isEmpty()) return top->data;
        cout << "Stack is Empty" << endl;
        return -1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack Empty" << endl;
            return;
        }
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack: ";
    s.display();

    cout << "Popped: " << s.pop() << endl;
    cout << "Top Element: " << s.peek() << endl;

    cout << "Stack after pop: ";
    s.display();

    return 0;
}
