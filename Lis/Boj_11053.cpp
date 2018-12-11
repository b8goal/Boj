#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int a[1001], dp[1001];
int main(void) {
	int n, mx = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		dp[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (a[i] > a[j] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
			mx = max(mx, dp[i]);
		}
	}
	printf("%d\n", mx);
	return 0;
}