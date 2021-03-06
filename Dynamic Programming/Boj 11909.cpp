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
#include <bitset>
#include <random>
#include <ctime>
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define REP(i,n) FOR(i,0,n)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
const int MOD = 10007;
const int INF = 0x7fffffff;
const int MIN = -32768 * 101;
const int MAXN = 100000 + 1;
const long double PI = 3.141592653589793238462643383279502884197;
int p[901];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y % x ? gcd(y, x%y) : x; }

int a[2222][2222], cache[2222][2222], dx[2] = { 1,0 }, dy[2] = { 0,1 };
int n, mn;
int f(int x, int y) {
	if (x == n - 1 && y == n - 1) return 0;
	int& ret = cache[x][y];
	if (ret != -1) return ret;
	ret = (1 << 30);
	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx>n - 1 || ny>n - 1) continue;
		ret = min(ret, f(nx, ny) + max(0, a[nx][ny] - a[x][y] + 1));

	}
	return ret;
}
int main(void) {
	mn = INF;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	memset(cache, -1, sizeof cache);
	printf("%d\n", f(0, 0));
	return 0;
}