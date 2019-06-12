#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000000
using namespace std;

char a[5050][5050];
int n, ans;
vector<int> v;

vector<int> makeTable(string pattern,int k) {
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	int j = 0;
	
	for (int i = 1; i < k; ++i) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
			ans = max(ans, table[i]);
		}
	}
	return table;
}

int main(void) {
	scanf("%s", &a[0]);
	int i = 0;
	for (; a[0][i]; ++i);
	n = i;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < n - i; ++j) {
			a[i][j] = a[i - 1][j + 1];
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << a[i] << '\n';
		makeTable(a[i], n - i);
	}
	cout << ans << '\n';
	return 0;
}