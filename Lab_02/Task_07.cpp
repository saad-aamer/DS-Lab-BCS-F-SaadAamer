#include <iostream>
using namespace std;

class employee {
    int id ,salary;
    string name;
public:
    employee() : id(0), name(""),salary(0) {}
    employee(int i, string n, int s) : id(i), name(n),salary(s){}
    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Salary: "<<salary<<endl;
    }
    int getSalary() const { return salary; }
};

class department {
    string dep_name;
    int no_of_emp;
    employee* e;  
public:
    department() :dep_name(""), no_of_emp(0), e(nullptr) {}

    department(string n, int n_emp, employee* emp)
        :dep_name(n), no_of_emp(n_emp) {
        e = new employee[no_of_emp];
        for (int i = 0; i < no_of_emp; ++i) {
            e[i] = emp[i];
        }
    }

    department(const department& other) {
        dep_name = other.dep_name;
        no_of_emp = other.no_of_emp;
        if (no_of_emp > 0) {
            e= new employee[no_of_emp];
            for (int i = 0; i < no_of_emp; ++i) {
                e[i] = other.e[i];
            }
        } else {
            e = nullptr;
        }
    }

    department& operator=(const department& other) {
        if (this == &other) return *this; 
        delete[] e;
        dep_name = other.dep_name;
        no_of_emp = other.no_of_emp;
        if (no_of_emp > 0) {
            e = new employee[no_of_emp];
            for (int i = 0; i < no_of_emp; ++i) {
                e[i] = other.e[i];
            }
        } else {
            e = nullptr;
        }
        return *this;
    }

    void display() const {
        cout << "Department Name: " << dep_name << endl;
        cout << "Number of employees: " << no_of_emp << endl;
        for (int i = 0; i < no_of_emp; ++i) {
            e[i].display();
        }
    }

    void averageSalary() const {
        int sum = 0;
        for (int i = 0; i < no_of_emp; i++) {
            sum += e[i].getSalary();
        }
        cout << "Average Salary: " << (no_of_emp > 0 ? sum / no_of_emp : 0) << endl;
    }

    void maxSalary() const {
        int max = 0;
        for (int i = 0; i < no_of_emp; i++) {
            if(e[i].getSalary() > max) {
                max = e[i].getSalary();
            }
        }
        cout << "Max Salary: " << max << endl;
    }
   
    ~department() {
        delete[] e;
    }
};

int main() {
    employee* d1_employees = new employee[2];
    d1_employees[0] = employee(1, "Saad", 50000);
    d1_employees[1] = employee(2, "Hassan", 65000);

    employee* d2_employees = new employee[3];
    d2_employees[0] = employee(1, "Ahmed", 50000);
    d2_employees[1] = employee(2, "Mubashir", 65000);
    d2_employees[2] = employee(3, "Ali", 70000);

    department* dep= new department[2];
    dep[0] = department("Household", 2, d1_employees);
    dep[1] = department("Grocery", 3, d2_employees);

    dep[0].display();
    dep[0].averageSalary();
    dep[0].maxSalary();

    dep[1].display();
    dep[1].averageSalary();
    dep[1].maxSalary();

    delete[] d1_employees;
    delete[] d2_employees;
    delete[] dep;

    return 0;
}
