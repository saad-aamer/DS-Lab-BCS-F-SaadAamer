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
    node* head;
public:
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
    void display() {
        node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << endl;
    }
    bool isPalindrome() {
        node* slow = head;
        node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        node* prev = nullptr;
        node* current = slow;
        node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        node* secondHalf = prev;
        node* firstHalf = head;
        bool palindrome = true;
        while (secondHalf != nullptr) {
            if (firstHalf->data != secondHalf->data) {
                palindrome = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return palindrome;
    }
};
int main() {
    linkedList l1;
     int size;
    cout<<"Enter The Number of Nodes you want to make: "<<endl;
    cin>>size;
    cout<<"Enter Values to the nodes in the List : "<<endl;
    for(int i=0;i<size;i++){
        int x;
        cin>>x;
        l1.insert(x);
    }
    if (l1.isPalindrome()) {
        cout << "The List is Palindrome!" << endl;
    } else {
        cout << "The List is not Palindrome!" << endl;
    }
    l1.display();
}
