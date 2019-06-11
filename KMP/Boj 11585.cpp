#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000000
using namespace std;

int n, ans;
vector<char> pattern, parent;

int gcd(int x, int y) {
	return y ? gcd(y, x%y) : x;
}

vector<int> makeTable(void) {
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
void KMP(void) {
	vector<int> table = makeTable();
	int patternSize = pattern.size();
	int parentSize = parent.size();
	int j = 0;
	for (int i = 0; i < parentSize-1; ++i) {
		while (j > 0 && parent[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (parent[i] == pattern[j]) {
			if (j == patternSize - 1) {
				++ans;
				j = table[j];
			}
			else
				++j;
		}
	}
}
int main(void) {
	scanf("%d", &n);
	pattern.resize(n,0);
	parent.resize(2 * n, 0);
	for (int i = 0; i < n; ++i)
		scanf(" %c", &parent[i]);
	for (int i = 0; i < n; ++i)
		parent[n + i] = parent[i];
	for (int i = 0; i < n; ++i)
		scanf(" %c", &pattern[i]);
	KMP();
	printf("%d/%d\n", ans / gcd(ans, n), n / gcd(ans, n));
	return 0;
}