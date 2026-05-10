#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<int> seen;
    int x;
    while (cin >> x) {
        if (seen.count(x)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
            seen.insert(x);
        }
    }
    return 0;
}