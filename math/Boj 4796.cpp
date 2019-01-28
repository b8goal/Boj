#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
typedef long long ll;
using namespace std;
const int MOD = 9901;
const int INF = 0x7fffffff;
const int MAXN = 300;
int p[1000];
ll cache[61][61], a[31];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
long long i, w, sw, sum, l;
int main(void) {
	int tc=0;
	while (1) {
		int l, p, v;
		scanf("%d %d %d", &l, &p, &v);
		if (!l && !p && !v) break;
		printf("Case %d: %d\n", ++tc, v / p * l + v % p);
	}
	return 0;
}

