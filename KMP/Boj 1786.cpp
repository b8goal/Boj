#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000000
using namespace std;

int n, ans;
vector<int> v;

vector<int> makeTable(string pattern) {
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

void KMP(string parent, string pattern) {
	vector<int> table = makeTable(pattern);
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int j = 0;
	for (int i = 0; i < parentSize; ++i) {
		while (j > 0 && parent[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (parent[i] == pattern[j]) {
			if (j == patternSize - 1) {
				//v.push_back(i);
				v.push_back(i-patternSize+2);
				j = table[j];
			}
			else {
				++j;
			}
		}
	}
}

int main(void) {
	string pattern, parent;
	getline(cin, parent);
	getline(cin, pattern);
	KMP(parent, pattern);
	cout << v.size() << '\n';
	for (auto it : v)
		cout << it << ' ';
	return 0;
}