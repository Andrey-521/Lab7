#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> ReadNumbersFromFile(const string& filename) {
    ifstream in(filename);
    if (!in.is_open()) {
        cerr << "Error: Failed to open file " << filename << std::endl;
        return {};
    }
    std::vector<int> data;
    int value;
    while (in >> value) {
        data.push_back(value);
    }
    return data;
}

int main() {
    vector<int> data = ReadNumbersFromFile("Numbers.txt");
    if (data.empty()) {
        cout << "No data to process.\n";
        return 0;
    }

    else {
        cout << "Original dataset:\n";
        for (const auto& x : data) {
            cout << x << " ";
        }
        cout << "\n";

        // a) Число n
        int n;
        cout << "Enter number n for searching: ";
        cin >> n;
        size_t cnt = count(data.begin(), data.end(), n);
        cout << "Number " << n << " occurs " << cnt << " time(s).\n";
        if (cnt > 0) {
            cout << "Position (index starting from 0): ";
            for (size_t i = 0; i < data.size(); ++i) {
                if (data[i] == n) {
                    cout << i << " ";
                }
            }
            cout << endl;
        }

        // b) Четные элементы
        size_t even_count = count_if(data.begin(), data.end(),
            [](int x) { return x % 2 == 0; });
        size_t odd_count = data.size() - even_count;
        cout << "Number of even elements: " << even_count << endl;
        if (even_count > odd_count) {
            int sum_even = accumulate(data.begin(), data.end(), 0,
                [](int acc, int x) { return acc + (x % 2 == 0 ? x : 0); });
            cout << "Summ of even elements: " << sum_even << endl;
        }
        else {
            int sum_all = accumulate(data.begin(), data.end(), 0);
            cout << "Summ of all elements: " << sum_all << std::endl;
        }
        cout << "Index of even elements: ";
        for (size_t i = 0; i < data.size(); ++i) {
            if (data[i] % 2 == 0) {
                std::cout << i << " ";
            }
        }
        std::cout << std::endl;

        // c) Сортировка
        std::vector<int> sorted = data;
        std::sort(sorted.begin(), sorted.end());
        std::cout << "Sorted dataset:\n";
        for (const auto& x : data) {
            cout << x << " ";
        }
        cout << "\n";

        // d) Перестановка первого и последнего элемента
        if (!data.empty()) {
            std::swap(data.front(), data.back());
            std::cout << "After swapping the first and last elements:\n";
            for (const auto& x : data) {
                cout << x << " ";
            }
            cout << "\n";
        }
	    return 0;
    }
    
}
