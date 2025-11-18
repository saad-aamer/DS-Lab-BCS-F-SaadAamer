#include <iostream>
using namespace std;

class box {
private:
    int* value;

public:
    box(int v = 0) {
        value = new int(v);
    }

    ~box() {
        delete value;
    }

    box(const box& other) {
        value = new int(*other.value);
    }

    box& operator=(const box& other) {
        if (this != &other) {
            delete value;
            value = new int(*other.value);
        }
        return *this;
    }

    void set(int v) {
        *value = v;
    }

    int get() const {
        return *value;
    }
};

int main() {
    box b1(10);
    box b2 = b1;
    b2.set(20);
     cout << "b1: " << b1.get() << endl;
    cout << "b2: " << b2.get() << endl;

    box b3;
    b3 = b1;
    b3.set(30);
    cout << "b1: " << b1.get() << endl;
    cout << "b3: " << b3.get() << endl;

    return 0;
}
