#include <iostream>
#include <list>
#include <string>
using namespace std;

#define tableSize 100

class Hash {
private:
    list<pair<string, string>> table[tableSize];

    int hashFunc(const string& key) {
        int sum = 0;
        for (char c : key)
            sum += (int)c;
        return sum % tableSize;
    }

public:
    void insert(const string& key, const string& value) {
        int index = hashFunc(key);
        table[index].push_back({key, value});
        cout << "Key " << key << " inserted successfully!\n";
    }

    void remove(const string& key) {
        int index = hashFunc(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                cout << "Key " << key << " deleted successfully!\n";
                return;
            }
        }
        cout << "Key " << key << " not found for deletion!\n";
    }

    void search(const string& key) {
        int index = hashFunc(key);
        for (auto& p : table[index]) {
            if (p.first == key) {
                cout << "Search key " << key << ": " << p.second << endl;
                return;
            }
        }
        cout << "Key " << key << " not found!\n";
    }

    void displayIndex(int index) {
        if (index < 0 || index >= tableSize) {
            cout << "Invalid index!\n";
            return;
        }
        cout << "index " << index << ": ";
        for (auto& p : table[index]) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }

    void displayAll() {
        cout << "\nComplete Hash Table:\n";
        for (int i = 0; i < tableSize; i++) {
            if (!table[i].empty()) {
                cout << "index " << i << ": ";
                for (auto& p : table[i]) {
                    cout << "(" << p.first << ", " << p.second << ") ";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    Hash dict;

    dict.insert("AB", "FASTNU");
    dict.insert("CD", "CS");
    dict.insert("EF", "EXAMPLE");

    dict.search("AB");  
    dict.remove("EF");  

    dict.displayIndex(31);
    dict.displayIndex(35);  

    dict.displayAll();

    return 0;
}
