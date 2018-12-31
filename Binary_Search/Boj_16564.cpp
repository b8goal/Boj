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
#include <set>

#define C 10
using namespace std;

const int INF = 1000000000;
const int MOD = 998244353;
const int MAXN = 1000000;

long long x[MAXN];
int n, k;
long long s, e, ans;

bool f(long long m) {
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] >= m) break;
		cnt += m - x[i];
	}
	if (cnt <= k) return true;
	else return false;
}

int main(void) {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &x[i]);
	}
	sort(x, x + n);

	ans = 0;
	s = 0; e = x[n - 1] + k;
	while (s <= e) {
		long long mid = s + (e - s) / 2;
		if (f(mid)) {
			ans = max(ans, mid);
			s = mid+1;
		}
		else e = mid-1;
	}
	printf("%d\n", ans);
	return 0;
}