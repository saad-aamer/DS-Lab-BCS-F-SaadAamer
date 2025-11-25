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

    node* deleteNode(node* root, int val) {
        if (root == nullptr) return nullptr;
        if (val < root->data)
            root->left = deleteNode(root->left, val);
        else if (val > root->data)
            root->right = deleteNode(root->right, val);
        else {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            } else if (!root->left) {
                node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                node* temp = root->left;
                delete root;
                return temp;
            } else {
                node* minNode = findMin(root->right);
                root->data = minNode->data;
                root->right = deleteNode(root->right, minNode->data);
            }
        }
        return root;
    }
    
     node* findMin(node* root) {
        while (root && root->left)
            root = root->left;
        return root;
    }

    bool searchNode(node* root, int key) {
        if (root == nullptr)
            return false;
        if (root->data == key)
            return true;
        else if (key < root->data)
            return searchNode(root->left, key);
        else
            return searchNode(root->right, key);
    }

    void inorderTraversal(node* root) {
        if (!root)
            return;
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }

public:
    BST() : root(nullptr) {}

    void insert(int val) { root = insertNode(root, val); }

    void remove(int val) { root = deleteNode(root, val); }

    void search(int val) {
        cout << (searchNode(root, val) ? "Found!" : "Not Found!") << endl;
    }

    void display() {
        cout << "Inorder Traversal: ";
        inorderTraversal(root);
        cout << endl;
    }

};
int main() {
    BST tree;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values)
        tree.insert(v);

    tree.display();
    tree.search(60);
    tree.remove(20);
    tree.display();

    return 0;
}
