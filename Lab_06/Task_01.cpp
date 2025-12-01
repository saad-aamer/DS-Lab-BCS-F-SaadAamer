#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Stack {
public:
    int top;
    int size;
    char *arr;

    Stack(int s) {
        size = s;
        arr = new char[size];
        top = -1;
    }

    bool isFull() {
        return (top == size - 1);
    }

    bool isEmpty() {
        return (top == -1);
    }

    void push(char x) {
        if (!isFull()) arr[++top] = x;
    }

    char pop() {
        if (!isEmpty()) return arr[top--];
        return '\0';
    }

    char peek() {
        if (!isEmpty()) return arr[top];
        return '\0';
    }
};

// Check if operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Return priority of operators
int priority(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

/**************************
 * INFIX → POSTFIX
 **************************/
string infixToPostfix(string s) {
    Stack st(s.length());
    string result = "";

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (isalnum(ch)) result += ch;
        else if (ch == '(') st.push(ch);
        else if (ch == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                result += st.pop();
            }
            st.pop();
        }
        else {
            while (!st.isEmpty() && priority(st.peek()) >= priority(ch)) {
                result += st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.isEmpty()) result += st.pop();

    return result;
}

/**************************
 * POSTFIX → INFIX
 **************************/
string postfixToInfix(string s) {
    Stack st(s.length());
    string arr[100];
    int idx = -1;

    for (char c : s) {
        if (isalnum(c)) arr[++idx] = string(1, c);
        else {
            string b = arr[idx--];
            string a = arr[idx--];
            arr[++idx] = "(" + a + c + b + ")";
        }
    }
    return arr[idx];
}

/**************************
 * PREFIX → INFIX
 **************************/
string prefixToInfix(string s) {
    Stack st(s.length());
    string arr[100];
    int idx = -1;

    for (int i = s.length() - 1; i >= 0; i--) {
        char c = s[i];
        if (isalnum(c)) arr[++idx] = string(1, c);
        else {
            string a = arr[idx--];
            string b = arr[idx--];
            arr[++idx] = "(" + a + c + b + ")";
        }
    }
    return arr[idx];
}

/**************************
 * PREFIX → POSTFIX
 **************************/
string prefixToPostfix(string s) {
    Stack st(s.length());
    string arr[100];
    int idx = -1;

    for (int i = s.length() - 1; i >= 0; i--) {
        char c = s[i];
        if (isalnum(c)) arr[++idx] = string(1, c);
        else {
            string a = arr[idx--];
            string b = arr[idx--];
            arr[++idx] = a + b + c;
        }
    }
    return arr[idx];
}

/**************************
 * POSTFIX Evaluation
 **************************/
int evalPostfix(string s) {
    int st[100], top = -1;
    for (char c : s) {
        if (isdigit(c)) st[++top] = c - '0';
        else {
            int b = st[top--];
            int a = st[top--];
            switch (c) {
                case '+': st[++top] = a + b; break;
                case '-': st[++top] = a - b; break;
                case '*': st[++top] = a * b; break;
                case '/': st[++top] = a / b; break;
                case '^': st[++top] = pow(a, b); break;
            }
        }
    }
    return st[top];
}

/**************************
 * MAIN
 **************************/
int main() {
    string infix = "A+(B*C)";
    cout << "Infix: " << infix << endl;

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    cout << "Postfix -> Infix: " << postfixToInfix(postfix) << endl;

    string prefix = "+A*BC";
    cout << "Prefix: " << prefix << endl;

    cout << "Prefix -> Infix: " << prefixToInfix(prefix) << endl;
    cout << "Prefix -> Postfix: " << prefixToPostfix(prefix) << endl;

    string expVal = "53*62/+";
    cout << "Postfix Evaluation of 53*62/+: " << evalPostfix(expVal) << endl;

    return 0;
}
