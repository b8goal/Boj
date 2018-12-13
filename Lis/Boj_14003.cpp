#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int INF = 0x7fffffff;

int a[1000001], dp[1000001], idx[1000001], p[1000001];
void dfs(int h) {
	if (!h) return;
	dfs(p[h]);
	printf("%d ", a[h]);
}
int main(void) {
	int n, ans;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		dp[i] = INF;
		auto it = lower_bound(dp + 1, dp + 1 + i, a[i]) - dp; // dp의 i의 idx값
		dp[it] = a[i]; // a[i]값의 lower_boundry 위치를 찾아 a[i]값 대입
		idx[it] = i; // dp의 idx값에 i번째 위치 기록
		p[i] = idx[it - 1]; // pos를 기록하는 배열로 이전 idx 위치 기록
	}
	ans = lower_bound(dp + 1, dp + 1 + n, INF) - dp - 1;
	printf("%d\n", ans);
	dfs(idx[ans]);
	return 0;
}