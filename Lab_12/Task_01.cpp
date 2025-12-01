#include <iostream>
using namespace std;

int bruteForceSearch(string text, string pattern, int positions[]) {
    int n = text.length();
    int m = pattern.length();
    int count = 0;

    for (int i = 0; i <= n - m; i++) {
        int j = 0;

        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }

        if (j == m) {
            positions[count] = i;
            count++;
        }
    }

    return count;
}

int main() {
    string text = "the quick brown fox jumps over the lazy dog";
    string pattern = "the";

    int positions[50];

    int total = bruteForceSearch(text, pattern, positions);

    cout << "Occurrences found at indices: [ ";
    for (int i = 0; i < total; i++)
        cout << positions[i] << " ";
    cout << "]" << endl;

    return 0;
}
