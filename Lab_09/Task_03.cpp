#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    int height;

    node(int val) {
        data = val;
        left = right = nullptr;
        height = 1;
    }
};

class AVL {
    node* root;

    int getHeight(node* n) {
        return n ? n->height : 0;
    }

    int getBalance(node* n) {
        return n ? getHeight(n->left) - getHeight(n->right) : 0;
    }

    node* rightRotate(node* y) {
        node* x = y->left;
        node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    node* leftRotate(node* x) {
        node* y = x->right;
        node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    node* insertNode(node* root, int key) {
        if (!root)
            return new node(key);

        if (key < root->data)
            root->left = insertNode(root->left, key);
        else if (key > root->data)
            root->right = insertNode(root->right, key);
        else
            return root;

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        int balance = getBalance(root);

        // Left-Left Case
        if (balance > 1 && key < root->left->data)
            return rightRotate(root);

        // Right-Right Case
        if (balance < -1 && key > root->right->data)
            return leftRotate(root);

        // Left-Right Case
        if (balance > 1 && key > root->left->data) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right-Left Case
        if (balance < -1 && key < root->right->data) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void inorder(node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

public:
    AVL() { root = nullptr; }

    void insert(int val) { root = insertNode(root, val); }

    void display() {
        cout << "AVL Tree Inorder: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    AVL tree;
    
    int values[] = {10, 5, 15, 3, 7};  
    for(int v : values)
        tree.insert(v);

    tree.insert(12);

    tree.display();

    return 0;
}
