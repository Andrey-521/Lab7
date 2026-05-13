#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;
template<typename Iter>

void PrintResults(Iter first, Iter last) {
    for (Iter it = first; it != last; ++it) {
        cout << *it << endl;
    }
}

template<typename T>
void Process(const std::vector<T>& data) {
    vector<T> filtered;
    filtered.reserve(data.size());
    copy_if(data.begin(), data.end(),
        back_inserter(filtered),
        [](const T& x) { return x > 0; });
    
    PrintResults(filtered.begin(), filtered.end());
}

int main() {
    vector<int> numbers = { -2, 0, 3, 5, -1 };
    Process(numbers);

    vector<double> doubles = { -3.1, 1.4, 0.0, 2.9, -0.0 };
    Process(doubles);
    
    return 0;
}
