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
    void display() {
        node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << endl;
    }
};
node* mergeSortedLists(node* l1, node* l2){
       node temp(0);
    node* tail = &temp;
    while(l1!=nullptr && l2!=nullptr){
        if(l1->data< l2->data){
          tail->next=l1;
          l1=l1->next;
        }
        else{
            tail->next=l2;
            l2=l2->next;
        }
        tail=tail->next;
       
    }
    if(l1!=nullptr) tail->next=l1;
    if(l2!=nullptr) tail->next=l2;
    return temp.next;
}
  int main() {
    linkedList l1;
    cout<<"Enter Values for List 1: "<<endl;
    for(int i=0;i<3;i++){
        int x;
        cin>>x;
        l1.insert(x);
    }
  cout<<"Enter Values for List 2: "<<endl;
    linkedList l2;
    for(int i=0;i<3;i++){
        int x;
        cin>>x;
        l2.insert(x);
    }
  
    l1.display();
    l2.display();
    node* mergedHead = mergeSortedLists(l1.head, l2.head);
    cout << "Merged List: ";
    node* current = mergedHead;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
}