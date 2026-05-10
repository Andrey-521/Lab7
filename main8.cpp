#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void print_vec(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ' ';
        cout << v[i];
    }
    cout << '\n';
}

int main() {
    string filename;
    cout << "Enter input file name: ";
    if (!(cin >> filename)) return 0;

    ifstream fin(filename);
    if (!fin) {
        cerr << "Cannot open file: " << filename << '\n';
        return 1;
    }

    vector<int> data;
    int val;
    while (fin >> val) data.push_back(val);
    fin.close();

    if (data.empty()) {
        cout << "Input data is empty.\n";
        return 0;
    }

    cout << "Source vector: ";
    print_vec(data);

    // a) сколько раз встречается число n и позиции
    int n;
    cout << "Enter number n to search: ";
    cin >> n;

    int occurrences = count(data.begin(), data.end(), n);
    cout << "Number " << n << " meets " << occurrences << " times.\n";

    if (occurrences > 0) {
        cout << "Positions (1-based): ";
        auto it = find(data.begin(), data.end(), n);
        bool first = true;
        while (it != data.end()) {
            if (!first) cout << ' ';
            cout << (distance(data.begin(), it) + 1);
            first = false;
            it = find(it + 1, data.end(), n);
        }
        cout << '\n';
    }

    // b) количество четных элементов и номера этих элементов
    int cnt_even = count_if(data.begin(), data.end(), [](int x){ return x % 2 == 0; });
    cout << "Number of even elements: " << cnt_even << '\n';

    cout << "Even element numbers (1-based): ";
    bool any = false;
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i] % 2 == 0) {
            if (any) cout << ' ';
            cout << (i + 1);
            any = true;
        }
    }
    if (!any) cout << "(No)";
    cout << '\n';

    int cnt_odd = static_cast<int>(data.size()) - cnt_even;
    if (cnt_even > cnt_odd) {
        int sum_even = accumulate(data.begin(), data.end(), 0,
                                  [](int s, int x){ return s + (x % 2 == 0 ? x : 0); });
        cout << "There are more even numbers than odd numbers. The sum of the even numbers = " << sum_even << '\n';
    } else {
        int sum_all = accumulate(data.begin(), data.end(), 0);
        cout << "Even is not more than odd. The sum of all elements = " << sum_all << '\n';
    }

    // c) отсортировать данные и вывести исходный и отсортированный наборы
    vector<int> sorted = data;
    sort(sorted.begin(), sorted.end());
    cout << "Source vector: ";
    print_vec(data);
    cout << "Sorted vector: ";
    print_vec(sorted);

    // d) переставить местами первый и последний элемент
    if (data.size() >= 2) {
        swap(data.front(), data.back());
        cout << "Vector after swapping the first and last elements: ";
        print_vec(data);
    } else {
        cout << "There is nothing to swap (few elements).\n";
    }

    return 0;
}
