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
int dx[] = { 1,0,1 }, dy[] = { 0,1,1 },Map[16][16];
int mx, n;
struct Node {
	int sx, sy, ex, ey;
	Node(int sx1, int sy1, int ex1, int ey1) {
		sx = sx1, sy = sy1, ex = ex1, ey = ey1;
	}
};

int poss(Node p) {
	if (p.ex + 1 > n - 1 || p.ey + 1 > n - 1) return 0;
	if (Map[p.ex][p.ey] || Map[p.ex + 1][p.ey] || Map[p.ex][p.ey + 1] || Map[p.ex + 1][p.ey + 1]) return 0;
	return 1;
}
void dfs(Node p, int dir) {
	if (p.ex > n - 1 || p.ey > n - 1 || Map[p.ex][p.ey]) return;
	if (p.ex == n - 1 && p.ey == n - 1) {
		mx++;
		return;
	}
	for (int i = 0; i < 2; i++) {
		int nsx = p.ex, nsy = p.ey, nex = p.ex + dx[i], ney = p.ey + dy[i];
		if (dir == i || dir == 2)
			dfs(Node(nsx, nsy, nex, ney), i);
	}
	if (poss(p)) {
		int nsx = p.ex, nsy = p.ey, nex = p.ex + dx[2], ney = p.ey + dy[2];
		dfs(Node(nsx, nsy, nex, ney), 2);
	}
}
int main(void) {
	scanf("%d", &n);
	REP(i, n) REP(j, n) scanf("%d", &Map[i][j]);
	dfs(Node(0, 0, 0, 1), 1);
	printf("%d\n", mx);
	return 0;
}