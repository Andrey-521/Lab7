#include <algorithm>
#include <vector>
#include <iostream>

template<typename Iter>
void PrintResults(Iter first, Iter last) {
    for (Iter it = first; it != last; ++it) {
        std::cout << *it << std::endl;
    }
}

template<typename T>
void Process(const std::vector<T>& data) {
    std::vector<T> filtered;

    std::copy_if(
        data.begin(), data.end(),
        std::back_inserter(filtered),
        [](const T& x) { return x > 0; }
    );

    PrintResults(filtered.begin(), filtered.end());
}

int main() {
    std::vector<int> v = { -2, 0, 3, 5, -1 };
    Process(v);
    return 0;
}
