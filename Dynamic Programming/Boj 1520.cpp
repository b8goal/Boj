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
const int MAXN = 500;
using namespace std;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int p[100], a[MAXN + 1][MAXN + 1], cache[MAXN + 1][MAXN + 1];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int min(int x, int y) { return x > y ? y : x; }
int max(int x, int y) { return x > y ? x : y; }
int n, m;

int go(int x, int y) {
	if (x == n-1 && y == m-1) return 1;
	int& ret = cache[x][y];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1 || a[nx][ny] >= a[x][y])continue;
		ret += go(nx, ny);
	}
	return ret;
}
int main(void) {
	memset(cache, -1, sizeof cache);
	scanf("%d %d", &n, &m);
	REP(i,n)
		REP(j,m)
		scanf("%d", &a[i][j]);
	printf("%d\n", go(0,0));
	return 0;
}