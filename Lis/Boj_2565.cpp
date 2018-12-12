#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int INF = 0x7fffffff;
int a[501], dp[501];
int main(void) {
	int n, x, y, mx = -1, tmp = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		a[x] = y;
		dp[x] = 1;
		tmp = max(x, tmp);
	}
	for (int i = 1; i <= tmp; i++) {
		for (int j = 1; j <= i; j++) {
			if (!a[i] || !a[j]) continue;
			if (a[i] > a[j] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
			mx = max(mx, dp[i]);
		}
	}
	printf("%d\n", n - mx);
	return 0;
}