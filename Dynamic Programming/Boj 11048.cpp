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
typedef long long ll;
using namespace std;
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define REP(i,n) FOR(i,0,n) 
const int MOD = 1e9 + 7;
const int INF = 0x7fffffff;
const int MAXN = 300;
int p[1000001], a[1001][1001], cache[1001][1001];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int min(int x, int y) { return x > y ? y : x; }
int max(int x, int y) { return x > y ? x : y; }

int n, m;
int go(int x, int y) {
	if (x > n || y > m) return 0;
	int& ret = cache[x][y];
	if (ret != -1) return ret;
	ret = a[x][y];
	ret += max({ go(x + 1,y),go(x,y + 1),go(x + 1,y + 1) });
	return ret;
}
int main(void) {
	memset(cache, -1, sizeof cache);
	scanf("%d %d", &n, &m);
	FOR(i, 1, n + 1)
		FOR(j, 1, m + 1)
			scanf("%d", &a[i][j]);
	printf("%d\n",go(0,0));
	return 0;
}