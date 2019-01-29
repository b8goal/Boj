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
	while (1) {
		int a, _a, b, _b, c, _c, d, _d, cnt = 0;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (!a && !b && !c && !d)break;
		while (1) {
			if (a == b && b == c && c == d) {
				printf("%d\n", cnt);
				break;
			}
			_a = a; _b = b; _c = c; _d = d;
			a = abs(_a - _b); b = abs(_b - _c); c = abs(_c - _d); d = abs(_d - _a);
			cnt++;
		}
	}
	return 0;
}