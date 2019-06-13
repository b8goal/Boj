#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
#define MOD 360000
using namespace std;

int n, x;
bool parent[720100], pattern[360100];
int pi[360100];
void makeTable() {
	int j = 0;
	for (int i = 1; i < MOD; ++i) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = pi[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			pi[i] = ++j;
		}
	}
}

void KMP() {
	int j = 0;
	for (int i = 0; i < 2*MOD; ++i) {
		while (j > 0 && parent[i] != pattern[j]) 
			j = pi[j - 1];
		if (parent[i] == pattern[j]) {
			if (j == MOD - 1) {
				cout << "possible" << '\n';
				exit(0);
			}
			else
				++j;
		}
	}
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		cin >> x;
		parent[x] = 1;
		parent[x + MOD] = 1;
	}
	for (int i = 0; i < n; ++i) {
		cin >> x;
		pattern[x] = 1;
	}
	makeTable();
	KMP();
	cout << "impossible" << '\n';
	return 0;
}