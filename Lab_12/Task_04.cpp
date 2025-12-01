#include <iostream>
using namespace std;

void buildLPS(string pat, int table[]) {
    int prev = 0;
    table[0] = 0;
    int idx = 1;

    while (idx < pat.length()) {
        if (pat[idx] == pat[prev]) {
            prev++;
            table[idx] = prev;
            idx++;
        } 
        else {
            if (prev != 0)
                prev = table[prev - 1];
            else {
                table[idx] = 0;
                idx++;
            }
        }
    }
}

int KMPSearchAll(string txt, string pat, int indexList[]) {
    int n = txt.length();
    int m = pat.length();
    int count = 0;

    int lps[100];
    buildLPS(pat, lps);

    int t = 0, p = 0;

    while (t < n) {
        if (txt[t] == pat[p]) {
            t++;
            p++;
        }

        if (p == m) {
            indexList[count++] = t - p;
            p = lps[p - 1];
        }
        else if (t < n && txt[t] != pat[p]) {
            if (p != 0) p = lps[p - 1];
            else t++;
        }
    }
    return count;
}

int main() {
    string text = "ababababc";
    string pattern = "abab";

    int foundAt[50];
    int matches = KMPSearchAll(text, pattern, foundAt);

    cout << "[";
    for (int i = 0; i < matches; i++) {
        cout << foundAt[i];
        if (i < matches - 1) cout << ", ";
    }
    cout << "]";

    return 0;
}
