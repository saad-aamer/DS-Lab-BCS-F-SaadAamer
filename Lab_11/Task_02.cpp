#include <iostream>
#include <string>
using namespace std;

#define tableSize 100

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
        cout << "Key " << key << " inserted successfully!\n";
    }

    void search(const string& key) {
        int index = hashFunc(key);
        Node* current = table[index];
        while (current) {
            if (current->key == key) {
                cout << "Search key " << key << ": " << current->value << endl;
                return;
            }
            current = current->next;
        }
        cout << "Key " << key << " not found!\n";
    }

    void remove(const string& key) {
        int index = hashFunc(key);
        Node* current = table[index];
        Node* prev = nullptr;

        while (current) {
            if (current->key == key) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    table[index] = current->next;
                }
                delete current;
                cout << "Key " << key << " deleted successfully!\n";
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Key " << key << " not found for deletion!\n";
    }

    void displayIndex(int index) {
        if (index < 0 || index >= tableSize) {
            cout << "Invalid index!\n";
            return;
        }
        Node* current = table[index];
        cout << "index " << index << ": ";
        while (current) {
            cout << "(" << current->key << ", " << current->value << ") ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    HashTable dict;

    dict.insert("AB", "FASTNU");
    dict.insert("CD", "CS");
    dict.insert("EF", "EXAMPLE");

    dict.search("AB");   
    dict.remove("EF");     

    dict.displayIndex(31); 
    dict.displayIndex(35);  

    return 0;
}
