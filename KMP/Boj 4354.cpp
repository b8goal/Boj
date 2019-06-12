#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000000
using namespace std;

string pattern;

vector<int> makeTable() {
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	int j = 0;
	for (int i = 1; i < patternSize; ++i) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
	return table;
}
int main(void) {
	while (cin >> pattern) {
		if (pattern == ".") break;
		vector<int> table = makeTable();
		int tableSize = table.size();
		if (table[tableSize - 1] == 0)
			cout << 1 << '\n';
		else {
			int k = tableSize - table[tableSize - 1];
			if (tableSize%k == 0)
				cout << tableSize / k << '\n';
			else
				cout << 1 << '\n';
		}
	}
	return 0;
}