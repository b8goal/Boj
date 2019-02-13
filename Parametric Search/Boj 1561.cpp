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
int max(int x, int y) { return x > y ? x : y; }
int n, m;
int a[10001];
ll f(ll x) {
	ll sum = 0;
	for (int i = 0; i < m; i++)
		sum += x / a[i];
	return sum;
}
int main(void) {
	scanf("%d %d", &n, &m);
	REP(i, m)scanf("%d", &a[i]);
	ll lo = 1, hi = 6e10, mid;
	if (n <= m) 
		printf("%d\n", n);
	else {
		n -= m;
		while (lo <= hi) {
			mid = lo + (hi - lo) / 2;
			f(mid) >= n ? hi = mid - 1 : lo = mid + 1;
		}
		int c = f(lo) - n;
		for (int i = m; i--;) {
			if (lo%a[i] == 0 && !c--) {
				printf("%d\n", i + 1);
				break;
			}
		}
	}
	return 0;
}