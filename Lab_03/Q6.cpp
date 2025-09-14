#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* child;

    node(int val) {
        data = val;
        next = nullptr;
        child = nullptr;
    }
};

class multiLevelLinkedList {
public:
    node* head;

    multiLevelLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int val) {
        node* newNode = new node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertChild(node* parent, int val) {
        if (parent == nullptr) return;
        node* newNode = new node(val);
        if (parent->child == nullptr) {
            parent->child = newNode;
        } else {
            node* temp = parent->child;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

   

    void flatten() {
        node* current = head;
        while (current != nullptr) {
            if (current->child != nullptr) {
                node* childHead = current->child;
                node* childTail = childHead;

                while (childTail->next != nullptr) {
                    childTail = childTail->next;
                }

                childTail->next = current->next;
                current->next = childHead;
                current->child = nullptr;
            }
            current = current->next;
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
    multiLevelLinkedList l1;
    l1.insertAtEnd(1);
    l1.insertAtEnd(2);
    l1.insertAtEnd(3);
    l1.insertChild(l1.head->next, 4);
    l1.insertChild(l1.head->next->next, 5);
  
    l1.flatten();
    l1.display();
    
    

    return 0;
}
