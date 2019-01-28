#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
typedef long long ll;
using namespace std;
const int MOD = 9901;
const int INF = 0x7fffffff;
const int MAXN = 300;
int p[1000], dp[250001], a[250001];
ll cache[61][61];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }

int main(void) {
	int n, m;
	while (1) {
		int n, mx = -INF;
		scanf("%d", &n);
		if (!n)break;
		memset(dp, 0, sizeof dp);
		memset(a, 0, sizeof a);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		dp[0] = a[0];
		for (int i = 1; i < n; i++) {
			dp[i] = max(dp[i - 1] + a[i], a[i]);
			mx = max(mx, dp[i]);
		}
		printf("%d\n", mx);
	}
	
	return 0;
}