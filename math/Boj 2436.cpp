#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
typedef long long ll;
using namespace std;
const int MOD = 9901;
const int INF = 0x7fffffff;
const int MAXN = 300;
//int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
ll abs(ll x, ll y) { return x - y > 0 ? x - y : y - x; }
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int main(void) {
	ll g, l, mn, x, y, i, j;
	mn = j = INF;
	scanf("%lld %lld", &g, &l);
	l /= g;
	for (i = 1; i*i <= l; ++i) {
		if (l%i || gcd(i, l / i) != 1) continue;
		x = i;
		y = l / i;
	}
	printf("%lld %lld\n", x*g, y*g);
	return 0;
}