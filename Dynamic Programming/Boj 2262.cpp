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
const int MOD = 1e9 + 9;
const int INF = 0x7fffffff;
const int MIN = -32768 * 101;
const int MAXN = 100000 + 1;
const long double PI = 3.141592653589793238462643383279502884197;
int p[100];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int min(int x, int y) { return x > y ? y : x; }
ll max(ll x, ll y) { return x > y ? x : y; }
int pow(int x, int y) {
	if (y == 0) return 0;
	if (y == 1) return x;
	if (y % 2 == 0) {
		int ret = pow(x, y / 2);
		return ret = (ret * ret);
	}
	else {
		int ret = pow(x, (y - 1) / 2);
		return ret = ret * ret*x;
	}
}
int a[257], cache[257][257], w[256][256];

int go(int i, int j) {
	int& ret = cache[i][j];
	if (ret != -1) return ret;
	if (i == j) return 0;
	cache[i][j] = 2000000000;
	for (int k = i; k < j; k++) {
		int temp = go(i, k) + go(k + 1, j);
		temp += abs(w[i][k] - w[k + 1][j]);
		ret = min(ret, temp);
	}
	return ret;
}

int main(void) {
	memset(cache, -1, sizeof cache);
	int n;
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, n) {
		w[i][i] = a[i];
		for (int j = i + 1; j < n; j++)
			w[i][j] = min(w[i][j - 1], a[j]);
	}
	printf("%d\n", go(0, n - 1));
	return 0;
}