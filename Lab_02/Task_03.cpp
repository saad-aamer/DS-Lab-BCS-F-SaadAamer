#include <iostream>
using namespace std;

class student {
    int id, marks;
    string name;
public:
    student() : id(0), marks(0), name("") {}
    student(int i, string n, int m) : id(i), name(n), marks(m) {}
    int getMarks() const { return marks; }
    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Marks: " << marks << endl;
    }
};

class course {
    int course_id;
    string course_name;
    int no_of_students;
    student* s;  
public:
    
    course() : course_id(0), course_name(""), no_of_students(0), s(nullptr) {}


    course(int id, string n, int n_stu, student* stu)
        : course_id(id), course_name(n), no_of_students(n_stu) {
        s = new student[no_of_students];
        for (int i = 0; i < no_of_students; ++i) {
            s[i] = stu[i];
        }
    }

    
    course(const course& other) {
        course_id = other.course_id;
        course_name = other.course_name;
        no_of_students = other.no_of_students;
        if (no_of_students > 0) {
            s = new student[no_of_students];
            for (int i = 0; i < no_of_students; ++i) {
                s[i] = other.s[i];
            }
        } else {
            s = nullptr;
        }
    }

    
    course& operator=(const course& other) {
        if (this == &other) return *this; 

        course_id = other.course_id;
        course_name = other.course_name;
        no_of_students = other.no_of_students;
        if (no_of_students > 0) {
            s = new student[no_of_students];
            for (int i = 0; i < no_of_students; ++i) {
                s[i] = other.s[i];
            }
        } else {
            s = nullptr;
        }
        return *this;
    }

    void display(){
        cout << "Course ID: " << course_id << ", Course Name: " << course_name << endl;
        cout << "Number of students: " << no_of_students << endl;
        for (int i = 0; i < no_of_students; ++i) {
            s[i].display();
        }
    }

    void averageMarks() {
        int sum = 0;
        for (int i = 0; i < no_of_students; i++) {
            sum += s[i].getMarks();
        }
        cout << "Average Marks: " << (no_of_students > 0 ? sum / no_of_students : 0) << endl;
    }

   
    ~course() {
        delete[] s;
    }
};

int main() {
    student* c1_students = new student[2];
    c1_students[0] = student(1, "Saad", 90);
    c1_students[1] = student(2, "Hassan", 85);

    course* courses = new course[1];
    courses[0] = course(1001, "DSA", 2, c1_students);

    courses[0].display();
    courses[0].averageMarks();

    delete[] c1_students;
    delete[] courses;

    return 0;
}
