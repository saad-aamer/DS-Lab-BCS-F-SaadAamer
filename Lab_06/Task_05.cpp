#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;

class Stack {
private:
    int top;
    int size;
    char *s;

public:
    Stack(int n) {
        size = n;
        s = new char[size];
        top = -1;
    }

    void push(char c) {
        if (top == size - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        s[++top] = c;
    }

    char pop() {
        if (top == -1) {
            return '\0';
        }
        return s[top--];
    }

    char peek() {
        if (top == -1) return '\0';
        return s[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string infixToPostfix(const char* infix) {
    Stack st(strlen(infix));
    string postfix = "";

    for (int i = 0; infix[i]; i++) {
        char c = infix[i];

        if (isdigit(c)) {
            postfix += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                postfix += st.pop();
            }
            st.pop(); // remove '('
        }
        else if (isOperator(c)) {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(c)) {
                postfix += st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isEmpty()) {
        postfix += st.pop();
    }

    return postfix;
}

int evaluatePostfix(const string& postfix) {
    int stack[100], top = -1;

    for (int i = 0; postfix[i]; i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            stack[++top] = c - '0';
        } else {
            int b = stack[top--];
            int a = stack[top--];
            switch(c) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
                case '^': stack[++top] = pow(a, b); break;
            }
        }
    }
    return stack[top];
}

int main() {
    const char* infix = "3+4*2/(1-5)^2^3";
    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;
    cout << "Postfix Evaluation: " << evaluatePostfix(postfix) << endl;
    return 0;
}
