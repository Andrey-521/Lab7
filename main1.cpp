#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename C>
void Print(const C c, const string delim) {
	bool first = true;
	for (const auto elem : c) {
		if (!first) cout << delim;
		first = false;
		cout << elem;
	}
	cout << "\n";
}

int main() {
	vector<int> data = {1, 2, 3};
	Print(data, ", ");
}