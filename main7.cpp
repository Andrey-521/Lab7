#include <iostream>
#include <vector>
#include <algorithm>
 
template <typename Iter>
Iter Unique(Iter first, Iter last) {
    if (first == last) return last;
    Iter res = first;
    Iter it = first;
    ++it;
    for (; it != last; ++it) {
        if (!(*res == *it)) {
            ++res;
            *res = *it;
        }
    }
    ++res;
    return res;
}
 
int main() {
    std::vector<int> a = {1,1,2,2,2,3,1,1,4};
    auto new_end = Unique(a.begin(), a.end());
 
    std::cout << "New length: " << std::distance(a.begin(), new_end) << "\n";
    std::cout << "Items up to new_end: ";
    for (auto it = a.begin(); it != new_end; ++it) std::cout << *it << ' ';
    std::cout << "\n";
 
    std::cout << "Remainder: ";
    for (auto it = new_end; it != a.end(); ++it) std::cout << *it << ' ';
    std::cout << "\n";
    return 0;
}