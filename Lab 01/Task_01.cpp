#include <iostream>
using namespace std;

class bankaccount {
private:
    string name;
    int bankid;
    int balance;

public:
    bankaccount() {
        name = "N/A";
        bankid = 0;
        balance = 0;
    }

    bankaccount(string acc_name, int acc_id, int initial_balance) {
        name = acc_name;
        bankid = acc_id;
        balance = initial_balance;
    }

    bankaccount(const bankaccount &other) {
        name = other.name;
        bankid = other.bankid;
        balance = other.balance;
    }

    void deposit(int amount) {
        balance += amount;
    }

    void withdraw(int amount) {
        if (amount <= balance) {
            balance -= amount;
        }
    }

    int getbalance() const {
        return balance;
    }

    string getname() const {
        return name;
    }

    int getid() const {
        return bankid;
    }
};

int main() {
    bankaccount account1;
    cout << "Account1 -> Name: " << account1.getname() 
         << ", ID: " << account1.getid() 
         << ", Balance: " << account1.getbalance() << endl;

    bankaccount account2("Saad", 101, 1000);
    cout << "Account2 -> Name: " << account2.getname() 
         << ", ID: " << account2.getid() 
         << ", Balance: " << account2.getbalance() << endl;

    bankaccount account3(account2);
    account3.withdraw(200);
    cout << "Account3 -> Name: " << account3.getname() 
         << ", ID: " << account3.getid() 
         << ", Balance: " << account3.getbalance() << endl;

    cout << "Account2 -> Name: " << account2.getname() 
         << ", ID: " << account2.getid() 
         << ", Balance: " << account2.getbalance() << endl;

    return 0;
}
