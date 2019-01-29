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

int a, m, s;
double r(int a, int m, int s) {
	double val = s % m / double(m);
	s = (a * s + 1) % m;
	return val;
}
int main(void) {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, mx;
		scanf("%d", &n);
		mx = n;
		while (n != 1) {
			if (n % 2 == 0) n /= 2;
			else
				n = n * 3 + 1;
			mx = max(mx, n);
		}
		printf("%d\n", mx);
	}
	return 0;
}