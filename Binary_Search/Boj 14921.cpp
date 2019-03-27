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
int gcd(int x, int y) { return y%x ? gcd(y, x%y) : x; }

int a[100001], ans[2];

int main(void) {
	int n, mx;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	mx = 100000000 * 2 + 5;
	for (int i = 1; i < n; i++) {
		int lo, hi, mid, t;
		t = i - 1;
		lo = i; hi = n - 1;
		while (lo <= hi) {
			mid = lo + (hi - lo) / 2;
			if (mx > abs(a[t] + a[mid])) {
				ans[0] = a[t];
				ans[1] = a[mid];
				mx = abs(a[t] + a[mid]);
			}
			if (a[t] + a[mid] > 0)
				hi = mid - 1;
			else
				lo = mid + 1;
		}
	}
	printf("%d\n", ans[0]+ans[1]);
	return 0;
}