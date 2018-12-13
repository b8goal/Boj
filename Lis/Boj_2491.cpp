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

int a[100001], dp[100001];
int main(void) {
	int n, ans = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf("%d", &a[i]);
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] >= a[i - 1]) dp[i] = dp[i - 1] + 1;
		else dp[i] = 1;
		ans = max(ans, dp[i]);
	}
	memset(dp, 0, sizeof dp);
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] <= a[i - 1]) dp[i] = dp[i - 1] + 1;
		else dp[i] = 1;
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}