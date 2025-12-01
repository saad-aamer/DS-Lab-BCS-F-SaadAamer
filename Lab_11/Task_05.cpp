#include <iostream>
#include <string>
using namespace std;

#define TABLE_SIZE 15

struct Student {
    int roll;
    string name;
    bool occupied;  
    bool deleted;  
};

class StudentHashTable {
private:
    Student table[TABLE_SIZE];

    int hashFunc(int roll) {
        return roll % TABLE_SIZE;
    }

public:
    StudentHashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i].occupied = false;
            table[i].deleted = false;
        }
    }

    void InsertRecord(int roll, const string& name) {
        int index = hashFunc(roll);
        int attempt = 0;

        while (attempt < TABLE_SIZE) {
            int newIndex = (index + attempt * attempt) % TABLE_SIZE;
            if (!table[newIndex].occupied || table[newIndex].deleted) {
                table[newIndex].roll = roll;
                table[newIndex].name = name;
                table[newIndex].occupied = true;
                table[newIndex].deleted = false;
                cout << "Inserted (" << roll << ", " << name << ") at index " << newIndex << endl;
                return;
            }
            attempt++;
        }

        cout << "Hash table is full! Cannot insert record.\n";
    }

    void SearchRecord(int roll) {
        int index = hashFunc(roll);
        int attempt = 0;

        while (attempt < TABLE_SIZE) {
            int newIndex = (index + attempt * attempt) % TABLE_SIZE;
            if (table[newIndex].occupied && !table[newIndex].deleted && table[newIndex].roll == roll) {
                cout << "Record found: " << table[newIndex].name << endl;
                return;
            }
            if (!table[newIndex].occupied && !table[newIndex].deleted) {
                break;
            }
            attempt++;
        }

        cout << "Record not found\n";
    }

    void Display() {
        cout << "\nHash Table Contents:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i].occupied && !table[i].deleted) {
                cout << "Index " << i << ": (" << table[i].roll << ", " << table[i].name << ")\n";
            }
        }
    }
};

int main() {
    StudentHashTable sht;

    sht.InsertRecord(1, "Alice");
    sht.InsertRecord(16, "Bob");   
    sht.InsertRecord(31, "Charlie");

    sht.SearchRecord(16); 
    sht.SearchRecord(2);  

    sht.Display();

    return 0;
}
