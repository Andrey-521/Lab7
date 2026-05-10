#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string,int> cnt;
    string s;
    while (cin >> s) {
        cout << ++cnt[s] << '\n';
    }
    return 0;
}