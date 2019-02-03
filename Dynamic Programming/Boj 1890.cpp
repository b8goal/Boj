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
const int MAXN = 101;
using namespace std;
int p[1000001], a[MAXN][MAXN];
ll cache[MAXN][MAXN];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int min(int x, int y) { return x > y ? y : x; }
int max(int x, int y) { return x > y ? x : y; }
int n, m;
ll go(int x, int y) {
	if (x > n-1 || y > n-1) return 0;
	if (x == n - 1 && y == n - 1) return 1;
	ll &ret = cache[x][y];
	if (ret != -1) return ret;
	ret = 0;
	ret += go(x + a[x][y],y)+ go(x,y + a[x][y]);
	return ret;
}
int main(void) {
	memset(cache, -1, sizeof cache);
	scanf("%d", &n);
	REP(i,n)
		REP(j,n)
			scanf("%d", &a[i][j]);
	
	printf("%lld\n",go(0,0));
	return 0;
}