#include <iostream>
using namespace std;

int rabinKarp(string text, string pattern, int positions[]) {
    int n = text.length();
    int m = pattern.length();
    int base = 256;
    int prime = 101;
    int hashP = 0, hashT = 0, h = 1;
    int count = 0;

    for (int i = 0; i < m - 1; i++)
        h = (h * base) % prime;

    for (int i = 0; i < m; i++) {
        hashP = (base * hashP + pattern[i]) % prime;
        hashT = (base * hashT + text[i]) % prime;
    }

    for (int i = 0; i <= n - m; i++) {
        if (hashP == hashT) {
            bool match = true;
            for (int j = 0; j < m; j++)
                if (text[i + j] != pattern[j])
                    match = false;
            if (match) {
                positions[count] = i;
                count++;
            }
        }
        if (i < n - m) {
            hashT = (base * (hashT - text[i] * h) + text[i + m]) % prime;
            if (hashT < 0)
                hashT = hashT + prime;
        }
    }
    return count;
}

int main() {
    string text = "Data structures and algorithms are fun. Algorithms make tasks easier.";
    string pattern = "Algorithms";

    int positions[50];
    int total = rabinKarp(text, pattern, positions);

    cout << "[";
    for (int i = 0; i < total; i++) {
        cout << positions[i];
        if (i != total - 1) cout << ", ";
    }
    cout << "]";

    return 0;
}
