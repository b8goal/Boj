#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
#define MOD 360000
using namespace std;

string pattern;
int n;

vector<int> makeTable(const string &pattern) {
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
int main(void){
	cin >> n >> pattern;
	vector<int> table = makeTable(pattern);
	cout << n - table[pattern.size() - 1] << '\n';
	return 0;
}