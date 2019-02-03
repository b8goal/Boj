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
int p[100], a[MAXN + 1], sum[MAXN+1], cache[MAXN + 1][MAXN + 1];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int min(int x, int y) { return x > y ? y : x; }
int max(int x, int y) { return x > y ? x : y; }
int n, m;

int go(int x, int y) {
	if (x == y) return 0;
	int& ret = cache[x][y];
	if (ret != -1)return ret;
	FOR(k, x, y) {
		int temp = go(x, k) + go(k + 1, y) + sum[y] - sum[x - 1];
		if (ret == -1 || ret > temp)
			ret = temp;
	}
	return ret;
}
int main(void) {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		memset(cache, -1, sizeof cache);
		memset(sum, 0, sizeof sum);
		scanf("%d", &n);
		FOR(i, 1, n + 1) scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
		printf("%d\n", go(1, n));
	}
	return 0;
}