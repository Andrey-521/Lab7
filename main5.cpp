#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
template <typename T>

void Duplicate(vector<T>& v) {
    size_t original_size = v.size();
    v.reserve(original_size * 2);
    for (size_t i = 0; i < original_size; ++i) {
        v.push_back(v[i]);
    }
}

int main() {
    vector<int> numbers;
    int num;
    while (cin >> num && num != 0) {
        numbers.push_back(num);
    }

    if (numbers.empty()) {
        cout << "No numbers.\n";
    }
    else Duplicate(numbers);
    for (const auto& num : numbers) {
        cout << num << " ";
    }

    return 0;
}
