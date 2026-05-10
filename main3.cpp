#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;

    vector<bool> intersect(26, false);
    for (char c : s) {
        if (isalpha((unsigned char)c)) {
            c = tolower(c);
            intersect[c - 'a'] = true;
        }
    }

    while (cin >> s) {
        vector<bool> present(26, false);
        for (char c : s) {
            if (isalpha((unsigned char)c)) {
                c = tolower(c);
                present[c - 'a'] = true;
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (!present[i]) intersect[i] = false;
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (intersect[i]) cout << char('a' + i);
    }
    cout << '\n';
    return 0;
}   