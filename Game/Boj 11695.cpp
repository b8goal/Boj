#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

long long a, b;
int main(void) {
	int n, m, x;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		a = 0;
		for (int j = 0; j < m; j++) {
			cin >> x;
			a += x;
		}
		b ^= a;
	}
	puts(b ? "august14" : "ainta");
	return 0;
}