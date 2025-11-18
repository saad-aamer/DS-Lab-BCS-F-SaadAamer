#include <iostream>
using namespace std;

class exam {
private:
    char* student_name;
    char* exam_date;
    int score;

public:
    exam() {
        student_name = nullptr;
        exam_date = nullptr;
        score = 0;
    }

    ~exam() {
        delete[] student_name;
        delete[] exam_date;
    }

    void setdetails(const char* name, const char* date, int marks) {
        delete[] student_name;
        delete[] exam_date;

        int len1 = 0;
        for (int i = 0; name[i] != '\0'; i++) {
            len1++;
        }
        student_name = new char[len1 + 1];
        for (int i = 0; i < len1; i++) {
            student_name[i] = name[i];
        }
        student_name[len1] = '\0';

        int len2 = 0;
        for (int i = 0; date[i] != '\0'; i++) {
            len2++;
        }
        exam_date = new char[len2 + 1];
        for (int i = 0; i < len2; i++) {
            exam_date[i] = date[i];
        }
        exam_date[len2] = '\0';

        score = marks;
    }

    void display() const {
        cout << "Student: " << student_name 
             << ", Date: " << exam_date 
             << ", Score: " << score << endl;
    }
};

int main() {
    exam e1;
    e1.setdetails("Saad", "2025-09-01", 95);
    e1.display();

    exam e2 = e1;
    e2.display();

    return 0;
}
