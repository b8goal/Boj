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
int n, m, mx;
int a[200001];
int f(int x) {
	int prev = a[0], res = 1, tmp = a[n-1]-a[0];
	for (int i = 1; i < n; i++) {
		int cur = a[i];
		//printf("%d\n", x);
		if (cur - prev >= x) {
			tmp = min(tmp, cur - prev);
			res++;
			prev = cur;
		}
		if (res == m)break;
	}
	return res;
}
int main(void) {
	scanf("%d %d", &n, &m);
	REP(i, n)scanf("%d", &a[i]);
	int lo = 0, hi = 1e9-1, mid;
	sort(a, a + n);
	while (lo <= hi) {
		mid = lo + (hi - lo) / 2;
		f(mid) >=m ? lo = mid + 1 : hi = mid - 1;
	}
	printf("%d\n", f(lo));
	return 0;
}