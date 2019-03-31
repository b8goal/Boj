#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

int a[50001], cache[4][50001];
int main(void) {
	int n, k, x;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		a[i] = a[i - 1] + x;
	}
	cin >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = k; j <= n; j++) {
			cache[i][j] = max(cache[i][j - 1], a[j] - a[j - k] + cache[i - 1][j - k]);
		}
	}
	cout << cache[3][n];
	return 0;
}