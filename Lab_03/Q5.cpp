#include<iostream>
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
class doublyNode {
public:
    int data;
    doublyNode* next;
    doublyNode* prev;
    doublyNode(int val) {
        data = val;
        next = nullptr;
        prev=nullptr;
    }
};
class singlyLinkedList {
    node* head;
    doublyNode* dhead;
public:
    singlyLinkedList() {
        head = nullptr;
        dhead = nullptr;
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
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    void displayDoubly() {
    doublyNode* current = dhead;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


    void convertIntoDoubly(){
      if(head==nullptr) return;
      dhead= new doublyNode(head->data);
      doublyNode * dcurrent=dhead;
      node* current =head->next;
      while(current!=nullptr){
        doublyNode*newNode=new doublyNode(current->data);
        dcurrent->next=newNode;
        newNode->prev=dcurrent;
        dcurrent=newNode;
        current=current->next;
      }
    }

    void convertToCircular(){
        if(head==nullptr) return;
        node* tail=head;
        while(tail->next!=nullptr){
            tail=tail->next;
        }
        tail->next=head;
    }
    void displayCircular() {
    if (head == nullptr) return;
    node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

  
};
int main() {
    singlyLinkedList l1;
    int size;
    cout<<"Enter The Number of Nodes you want to make: "<<endl;
    cin>>size;
    cout<<"Enter Values for List 1: "<<endl;
    for(int i=0;i<size;i++){
        int x;
        cin>>x;
        l1.insert(x);
    }
    l1.display();

    l1.convertIntoDoubly();
    l1.displayDoubly();
    l1.convertToCircular();
    l1.displayCircular();
}