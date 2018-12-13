#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

const int INF = 0x7fffffff;

pair<int, int> a[100001];
int dp[100001], idx[100001], p[100001], chk[500001];
void dfs(int h) {
	if (!h) return;
	dfs(p[h]);
	chk[a[h].first] = 1;
}
int main(void) {
	int n, ans;
	memset(chk, -1, sizeof chk);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { scanf("%d %d", &a[i].first, &a[i].second); chk[a[i].first] = 0; }
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		dp[i] = INF;
		auto it = lower_bound(dp + 1, dp + 1 + i, a[i].second) - dp; 
		dp[it] = a[i].second; 
		idx[it] = i;
		p[i] = idx[it - 1]; 
	}
	ans = lower_bound(dp + 1, dp + 1 + n, INF) - dp - 1;
	printf("%d\n", n-ans);
	dfs(idx[ans]);
	for (int i = 1; i <= n; i++)
		if (!chk[a[i].first]) printf("%d\n", a[i].first);
	return 0;
}