#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

void Alphabet(const vector<string> words) {
    set<char> common;
    for (char ch : words[0]) {
        common.insert(ch);
    }

    for (size_t i = 1; i < words.size(); ++i) {
        set<char> current;
        for (char ch : words[i]) {
            current.insert(ch);
        }
        set<char> new_common;
        set_intersection(common.begin(), common.end(),
            current.begin(), current.end(),
            inserter(new_common, new_common.begin()));
        common.swap(new_common);
    }

    for (char ch : common) {
        cout << ch;
    }
    cout << endl;
}

int main() {
    vector<string> words;
    string word;
    while (cin >> word && word != "-") {
        words.push_back(word);
    }
   
    if (words.empty()) {
        cout << "No words.\n";
    }
    else Alphabet(words);

    return 0;
}
