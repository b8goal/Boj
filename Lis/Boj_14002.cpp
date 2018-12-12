#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int INF = 0x7fffffff;
int a[1001], dp[1001], idx[1001], f[1001];
void dfs(int h) {
	if (!h) return;
	dfs(f[h]);
	printf("%d ", a[h]);
}
int main(void) {
	int n, x, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		dp[i] = INF;
		auto it = lower_bound(dp + 1, dp + 1 + i, a[i]) - dp;
		dp[it] = a[i];
		idx[it] = i;
		f[i] = idx[it - 1];
	}
	ans = lower_bound(dp + 1, dp + 1 + n, INF) - dp - 1;
	printf("%d\n", ans);
	dfs(idx[ans]);
	return 0;
}
