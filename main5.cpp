#include <iostream>
#include <vector>

template <typename T>
void Duplicate(std::vector<T>& v) {
    std::size_t n = v.size();
    for (std::size_t i = 0; i < n; ++i) {
        v.push_back(v[i]);
    }
}

int main() {
    std::vector<int> v = {1, 2, 3};
    Duplicate(v);
    for (auto x : v) std::cout << x << ' ';
    std::cout << '\n';
    return 0;
}