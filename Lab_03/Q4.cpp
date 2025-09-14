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
class circularLinkedList {
    node* head;
public:
    circularLinkedList() {
        head = nullptr;
    }
    void insert(int val) {
        node* newNode = new node(val);
        if (head == nullptr) {
            head = newNode;
            head->next=head;
        } else {
            node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next=head;
        }
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
int josephProblem(int n,int k){
    do{
        node*current=head;
        for(int i=1;i<k-1;i++){
            current=current->next;
        }
        
        node*temp=current->next;
        current->next=current->next->next;
        head=current->next;
        delete temp;
        
        
}while(head->next!=head);
return head->data;
}

 
};
int main() {
    circularLinkedList l1;
     int n;
    cout<<"Enter The Number of People: "<<endl;
    cin>>n;
    for(int i=1;i<=n;i++){
        l1.insert(i);
    }
    l1.displayCircular();
    int k;
    cout<<"Enter the nth number for which every person has to be eliminated: ";
    cin>>k;
    cout<<"result "<<l1.josephProblem(n,k);
}