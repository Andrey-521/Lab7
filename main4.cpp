#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void Count_Words(const vector<string> words) {
    map<string, int> counter;
    for (auto& word : words) {
        int count = ++counter[word];
        cout << count << endl;
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
    else Count_Words(words);

    return 0;
}
