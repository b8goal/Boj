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
int p[1000], dp[250001], v[250001];
ll cache[61][61];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }

int main(void) {
	int n, l, ans1, ans2,mx_idx1, mx_idx;
	ans1 = ans2 = 0;
	scanf("%d %d", &l, &n);
	for (int i = 1,a,b; i <= n; i++) {
		scanf("%d %d", &a, &b);
		if (ans1 < b - a) {
			ans1 = b - a;
			mx_idx1 = i;
		}
		for (int j = a; j <= b; j++) {
			if (!v[j]){
				v[j] = i;
				dp[i]++;
				if (ans2 < dp[i]) {
					ans2 = dp[i];
					mx_idx = i;
				}
			}
		}
	}
	printf("%d\n%d\n", mx_idx1, mx_idx);
	return 0;
}