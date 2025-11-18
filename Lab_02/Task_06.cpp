#include <iostream>
using namespace std;

class safeptr {
    int* ptr;
public:
    safeptr() {
        ptr = new int; 
        *ptr = 0;        
    }

    void setValue(int val) {
        *ptr = val;
    }

    int getValue() const {
        return *ptr;
    }

    void release() {
        delete ptr;
        ptr = nullptr;
    }

    ~safeptr() {
        delete ptr;  
    }
};

int main() {
    int marks[5] = {85, 90, 78, 92, 88};

    safeptr* students = new safeptr[5];

    for (int i = 0; i < 5; i++) {
        students[i].setValue(marks[i]);
    }

    cout << "Marks of students:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Student " << i + 1 << ": " << students[i].getValue() << endl;
    }
    for (int i = 0; i < 5; i++) {
        students[i].release();
    }

    delete[] students;

    return 0;
}
