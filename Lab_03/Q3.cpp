#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = nullptr;
    }
};

class linkedList {
public:
    node* head;

    linkedList() {
        head = nullptr;
    }

     void insert(int val) {
        node* newNode = new node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void reverseInGroups(int k) {
        if (head == nullptr || k <= 1) return;

        node* dummy = new node(0);
        dummy->next = head;
        node* prevGroupEnd = dummy;
        node* current = head;

        while (true) {
            node* groupStart = current;
            node* check = current;

            for (int i = 0; i < k; i++) {
                if (check == nullptr) {
                    head = dummy->next;
                    delete dummy;
                    return;
                }
                check = check->next;
            }

            node* prev = check;
            for (int i = 0; i < k; i++) {
                node* nextNode = current->next;
                current->next = prev;
                prev = current;
                current = nextNode;
            }

            prevGroupEnd->next = prev;
            prevGroupEnd = groupStart;
        }
    }

    void display() {
        node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    linkedList l1;
    for (int i = 1; i <= 8; i++) {
        l1.insert(i);
    }

    cout << "Original list: ";
    l1.display();

    int k = 3;
    l1.reverseInGroups(k);

    cout << "Reversed in groups of " << k << ": ";
    l1.display();

    return 0;
}
