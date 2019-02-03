#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <list>
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define REP(i,n) FOR(i,0,n) 
typedef unsigned long long ull;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 0x7fffffff;
const int MAXN = 1e4;
using namespace std;
int a[100 + 1], cache[MAXN + 1];
//int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
//void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int min(int x, int y) { return x > y ? y : x; }
int max(int x, int y) { return x > y ? x : y; }
int n, k;
int main(void) {
	memset(cache, -1, sizeof cache);
	scanf("%d %d", &n, &k);
	REP(i, n) scanf("%d", &a[i]);
	cache[0] = 0;
	FOR(i, 0, n)
		FOR(j, 0, k + 1)
		if (j - a[i] >= 0 && cache[j - a[i]] != -1)
			if (cache[j] == -1 || cache[j] > cache[j - a[i]] + 1)
				cache[j] = cache[j - a[i]] + 1;
	printf("%d\n", cache[k]);
	return 0;
}