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
double abs(double x, double y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int dx[] = { 1,0,1 }, dy[] = { 0,1,1 };
ll Map[35][35], cache[35][35][3];
int mx, n;
struct Node {
	int sx, sy, ex, ey;
	Node(int sx1, int sy1, int ex1, int ey1) {
		sx = sx1, sy = sy1, ex = ex1, ey = ey1;
	}
};

int poss(int x,int y) {
	if (x + 1 > n || y + 1 > n) return 0;
	if (Map[x][y] || Map[x + 1][y] || Map[x][y + 1] || Map[x + 1][y + 1]) return 0;
	return 1;
}

void print_Map() {
	for (int k = 0; k < 3; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				printf("%lld ", cache[i][j][k]);
			}
			puts("");
		}
		puts("");
	}
	
}
int main(void) {
	memset(cache, 0, sizeof  cache);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%lld", &Map[i][j]);
	cache[1][2][1] = 1;
	// k==0 위 k == 1 왼쪽 k==2 왼쪽 대각선 
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			if (Map[i][j] || j==2) continue;
			cache[i][j][0] = cache[i - 1][j][0] + cache[i - 1][j][2];
			cache[i][j][1] = cache[i][j - 1][1] + cache[i][j - 1][2];
			if (poss(i-1, j-1))
				cache[i][j][2] += cache[i - 1][j - 1][0] + cache[i - 1][j - 1][1] + cache[i - 1][j - 1][2];
		}
	}
	printf("%lld\n", cache[n][n][0] + cache[n][n][1] + cache[n][n][2]);
	return 0;
}
