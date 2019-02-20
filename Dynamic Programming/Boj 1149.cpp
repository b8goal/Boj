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
int p[100];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int min(int x, int y) { return x > y ? y : x; }
int max(int x, int y) { return x > y ? x : y; }

int a[1001][3], cache[1001][3];
int main(void) {
	int n;
	scanf("%d", &n);
	REP(i, n) REP(j, 3) scanf("%d", &a[i][j]);
	cache[0][0] = a[0][0]; cache[0][1] = a[0][1]; cache[0][2] = a[0][2];
	FOR(i,1, n) REP(j, 3) {
		cache[i][0] = min(cache[i - 1][1], cache[i - 1][2]) + a[i][0];
		cache[i][1] = min(cache[i - 1][0], cache[i - 1][2]) + a[i][1];
		cache[i][2] = min(cache[i - 1][0], cache[i - 1][1]) + a[i][2];
	}
	printf("%d\n", min({ cache[n - 1][0],cache[n - 1][1],cache[n - 1][2] }));
	return 0;
}