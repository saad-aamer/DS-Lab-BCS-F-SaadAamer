#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *left, *right;
    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
    node* root;

    
    node* insertNode(node* root, int key) {
        if (root == nullptr)
            return new node(key);
        if (key < root->data)
            root->left = insertNode(root->left, key);
        else if (key > root->data)
            root->right = insertNode(root->right, key);
        return root;
    }
 
    void inorderTraversal(node* root) {
        if (!root)
            return;
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }

   
    int nodesInRange(node* root, int x, int y) {
        if (!root)
            return 0;
        if (root->data >= x && root->data <= y)
            return 1 + nodesInRange(root->left, x, y) + nodesInRange(root->right, x, y);
        else if (root->data < x)
            return nodesInRange(root->right, x, y);
        else
            return nodesInRange(root->left, x, y);
    }

public:
    BST() : root(nullptr) {}

    void insert(int val) { root = insertNode(root, val); }
    void display() {
        cout << "Inorder Traversal: ";
        inorderTraversal(root);
        cout << endl;
    }
    void countInRange(int x, int y) {
        cout << "Nodes in range [" << x << "," << y << "]: " << nodesInRange(root, x, y) << endl;
    }
};

int main() {
    BST tree;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values)
        tree.insert(v);

    tree.display();
    tree.countInRange(10, 50);

    return 0;
}
