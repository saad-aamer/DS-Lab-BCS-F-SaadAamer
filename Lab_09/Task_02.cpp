#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    int height;

    Node(int val) {
        data = val;
        left = right = nullptr;
        height = 1;
    }
};

class AVLTree {
    Node* root;

    int getHeight(Node* n) {
        if (!n) return 0;
        return n->height;
    }

    int getBalance(Node* n) {
        if (!n) return 0;
        return getHeight(n->left) - getHeight(n->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        x->right = y;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        return y;
    }

    Node* insertNode(Node* node, int key) {
        if (!node)
            return new Node(key);

        if (key < node->data)
            node->left = insertNode(node->left, key);
        else if (key > node->data)
            node->right = insertNode(node->right, key);
        else
            return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalance(node);

        if (balance > 1 && key < node->left->data)
            return rightRotate(node);

        if (balance < -1 && key > node->right->data)
            return leftRotate(node);

        if (balance > 1 && key > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

public:
    AVLTree() { root = nullptr; }

    void insert(int key) { root = insertNode(root, key); }

    void leftRotateRoot() {
        root = leftRotate(root);
    }

    void display() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    AVLTree tree;

    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : arr) tree.insert(v);

    tree.insert(55);
    cout << "Before Left Rotation on Root:" << endl;
    tree.display();

    tree.leftRotateRoot();
    cout << "After Left Rotation on Root:" << endl;
    tree.display();

    return 0;
}
