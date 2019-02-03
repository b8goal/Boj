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
const int MAXN = 2000;
using namespace std;
int p[1000001], a[MAXN + 1], cache[MAXN + 1][MAXN + 1];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int min(int x, int y) { return x > y ? y : x; }
int max(int x, int y) { return x > y ? x : y; }
int n, m, x, y;

int go(int x, int y) {
	if (x == y) return 1;
	else if (x + 1 == y)
		if (a[x] == a[y]) return 1;
		else return 0;
	int& ret = cache[x][y];
	if (ret != -1) return ret;
	if (a[x] != a[y]) return ret = 0;
	else return ret = go(x + 1, y - 1);
}
int main(void) {
	memset(cache, -1, sizeof cache);
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	scanf("%d", &m);
	REP(i, m) {
		scanf("%d %d", &x, &y);
		printf("%d\n", go(x-1,y-1));
	}
	return 0;
}