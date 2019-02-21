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

pii a[100001];
int dist[100001];
int main(void) {
	int n, mn, sum;
	mn = INF; sum = 0;
	scanf("%d", &n);
	scanf("%d %d", &a[0].first, &a[0].second);
	FOR(i, 1, n) {
		scanf("%d %d", &a[i].first, &a[i].second);
		dist[i-1] = abs(a[i].first - a[i - 1].first) + abs(a[i].second - a[i - 1].second);
		sum += dist[i-1];
	}
	FOR(i, 1, n-1) 
		mn = min(mn, sum - dist[i-1] - dist[i]+ abs(a[i+1].first - a[i - 1].first) + abs(a[i+1].second - a[i - 1].second));
	printf("%d\n", mn);
	return 0;
}