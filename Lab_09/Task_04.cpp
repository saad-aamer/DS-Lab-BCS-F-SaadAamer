#include <iostream>
using namespace std;

class node {
public:
    int data, height;
    node *left, *right;

    node(int val) {
        data = val;
        height = 1;
        left = right = nullptr;
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

        if (balance > 1 && key < root->left->data)
            return rightRotate(root);

        if (balance < -1 && key > root->right->data)
            return leftRotate(root);

        if (balance > 1 && key > root->left->data) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

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

    bool kthSmallest(node* root, int& k, int &result) {
        if (!root) return false;

        if (kthSmallest(root->left, k, result)) return true;

        k--;
        if (k == 0) {
            result = root->data;
            return true;
        }

        return kthSmallest(root->right, k, result);
    }

    bool kthLargest(node* root, int& k, int &result) {
        if (!root) return false;

        if (kthLargest(root->right, k, result)) return true;

        k--;
        if (k == 0) {
            result = root->data;
            return true;
        }

        return kthLargest(root->left, k, result);
    }

public:
    AVL() {
        root = nullptr;
    }

    void insert(int val) {
        root = insertNode(root, val);
    }

    void display() {
        cout << "AVL Tree Inorder: ";
        inorder(root);
        cout << endl;
    }

    void printHeights() {
        cout << "Left Height: " << getHeight(root->left) << endl;
        cout << "Right Height: " << getHeight(root->right) << endl;
    }

    void printKValues(int k) {
        int smallest = -1, largest = -1;
        int k1 = k, k2 = k;

        kthSmallest(root, k1, smallest);
        kthLargest(root, k2, largest);

        cout << k << "th Smallest: " << smallest << endl;
        cout << k << "th Largest: " << largest << endl;
    }
};

int main() {
    AVL tree;

    int values[] = {10, 5, 15, 3, 7, 12};
    for (int v : values)
        tree.insert(v);

    tree.display();

    tree.printKValues(2);

    tree.printHeights();

    return 0;
}
