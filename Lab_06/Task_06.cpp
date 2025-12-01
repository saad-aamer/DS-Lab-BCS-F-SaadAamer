#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;

class CharStack {
private:
    int top;
    int size;
    char *s;
public:
    CharStack(int n) {
        size = n;
        s = new char[size];
        top = -1;
    }
    void push(char c) { s[++top] = c; }
    char pop() { return (top == -1) ? '\0' : s[top--]; }
    char peek() { return (top == -1) ? '\0' : s[top]; }
    bool isEmpty() { return top == -1; }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperator(char c) {
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}

string infixToPrefix(const char* infix) {
    int n = strlen(infix);
    char rev[100];
    // Reverse infix and swap ( with )
    for (int i = 0; i < n; i++) {
        char c = infix[n-1-i];
        if (c=='(') rev[i]=')';
        else if (c==')') rev[i]='(';
        else rev[i]=c;
    }
    rev[n]='\0';

    CharStack st(n);
    string result = "";

    for (int i=0; rev[i]; i++) {
        char c = rev[i];
        if (isdigit(c)) result += c;
        else if (c=='(') st.push(c);
        else if (c==')') {
            while(!st.isEmpty() && st.peek() != '(')
                result += st.pop();
            st.pop();
        } else if (isOperator(c)) {
            while(!st.isEmpty() && precedence(st.peek()) >= precedence(c))
                result += st.pop();
            st.push(c);
        }
    }
    while(!st.isEmpty()) result += st.pop();

    // Reverse result to get prefix
    int len = result.length();
    string prefix = "";
    for (int i=len-1; i>=0; i--) prefix += result[i];

    return prefix;
}

int evaluatePrefix(const string& prefix) {
    int stack[100], top=-1;
    for (int i = prefix.length()-1; i>=0; i--) {
        char c = prefix[i];
        if (isdigit(c)) stack[++top] = c-'0';
        else {
            int a = stack[top--];
            int b = stack[top--];
            switch(c){
                case '+': stack[++top]=a+b; break;
                case '-': stack[++top]=a-b; break;
                case '*': stack[++top]=a*b; break;
                case '/': stack[++top]=a/b; break;
                case '^': stack[++top]=pow(a,b); break;
            }
        }
    }
    return stack[top];
}

int main() {
    const char* infix = "(3+4)*5-6/(1+2)";
    string prefix = infixToPrefix(infix);
    cout << "Prefix: " << prefix << endl;
    cout << "Prefix Evaluation: " << evaluatePrefix(prefix) << endl;
    return 0;
}
