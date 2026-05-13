#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template <typename Iter>
Iter Unique(Iter first, Iter last) {
    if (first == last) return last;
    Iter result = first;
    while (++first != last) {
        if (!(*result == *first) && ++result != first) {
            *result = move(*first);
        }
    }
    return ++result;
}
 
int main() {
    vector<int> v = { 1, 1, 2, 2, 3, 3, 3, 4, 5, 5, 6 };
    cout << "Before Unique: ";
    for (const auto& x : v) {
        cout << x << " ";
    }
    cout << "\n";

    auto new_end = Unique(v.begin(), v.end());
    v.erase(new_end, v.end());
    cout << "After Unique: ";
    for (const auto& x : v) {
        cout << x << " ";
    }
    return 0;
}
