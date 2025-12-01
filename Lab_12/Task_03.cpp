#include <iostream>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

void badCharTable(string pattern, int badChar[]) {
    for (int i = 0; i < 256; i++)
        badChar[i] = -1;
    for (int i = 0; i < pattern.length(); i++)
        badChar[(int)pattern[i]] = i;
}

int boyerMoore(string text, string pattern, int positions[]) {
    int n = text.length();
    int m = pattern.length();
    int badChar[256];
    badCharTable(pattern, badChar);

    int shift = 0;
    int count = 0;

    while (shift <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[shift + j])
            j--;

        if (j < 0) {
            positions[count++] = shift;
            shift += (shift + m < n) ? m - badChar[text[shift + m]] : 1;
        } else {
            shift += max(1, j - badChar[text[shift + j]]);
        }
    }
    return count;
}

int main() {
    string DNA = "ACGTACGTGACG";
    string pattern = "ACG";

    int positions[50];
    int total = boyerMoore(DNA, pattern, positions);

    cout << "[";
    for (int i = 0; i < total; i++) {
        cout << positions[i];
        if (i != total - 1) cout << ", ";
    }
    cout << "]";

    return 0;
}
