#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <functional>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

long long dp[70];

int main(void) {
	int tc;
	scanf("%d", &tc);
	for (int i = 0, n, d, ans; i < tc; i++) {
		ans = 0;
		scanf("%d %d", &n, &d);
		for (int i = 0, x, y, z; i < n; i++) {
			scanf("%d %d %d", &x, &y, &z);
			double t = (double) y /(double) z;
			if (double(d) <= t * (double)x)
				ans++;
		}
		printf("%d\n", ans);
	}
}