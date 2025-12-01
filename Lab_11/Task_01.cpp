#include <iostream>
#include <string>
using namespace std;

#define tableSize 10

struct Node {
    string key;
    string value;
    Node* next;
};

class HashTable {
public:
    Node* table[tableSize];

    HashTable() {
        for (int i = 0; i < tableSize; i++)
            table[i] = nullptr;
    }

    int hashFunc(const string& key) {
        int sum = 0;
        for (char c : key) sum += (int)c;
        return sum % tableSize;
    }

    void insert(const string& key, const string& value) {
        int index = hashFunc(key);
        Node* newNode = new Node{key, value, table[index]};
        table[index] = newNode;
    }

    void fetch(const string& key) {
        int index = hashFunc(key);
        Node* current = table[index];
        cout << "Values for key (" << key << "): ";
        bool found = false;
        while (current) {
            if (current->key == key) {
                cout << current->value << " ";
                found = true;
            }
            current = current->next;
        }
        if (!found) cout << "none";
        cout << endl;
    }

    void show() {
        for (int i = 0; i < tableSize; i++) {
            cout << i << " : ";
            Node* current = table[i];
            while (current) {
                cout << "(" << current->key << "," << current->value << ") ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable myHash;

    myHash.insert("A", "aaaaa");
    myHash.insert("B", "bbbbb");
    myHash.insert("C", "ccccc");
    myHash.insert("A", "zzzzz");

    cout << "\nHash Table:\n";
    myHash.show();

    cout << "\nFetching duplicate key 'A':\n";
    myHash.fetch("A");

    return 0;
}
