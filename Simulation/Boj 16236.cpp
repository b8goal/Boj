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

struct shark{
	int x, y, sz, c;
	shark(int x1, int y1, int sz1, int c1) {
		x = x1, y = y1, sz = sz1, c = c1;
	};
};

int Map[25][25], dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 }, chk[25][25], dis[25][25];
int n;
queue<pair<pair<int, int>, int> > q;
int poss(shark s) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (Map[i][j] != 0 && Map[i][j] < s.sz)
				cnt++;
		}
	}
	return cnt;
}

int bfs(shark s) {
	int dist = 1000000;
	memset(dis, 0, sizeof dis);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (Map[i][j] != 0 && Map[i][j] != 9 && Map[i][j] < s.sz) {
				memset(chk, 0, sizeof chk);
				queue<pair<pair<int, int>, int> > qq;
				qq.push(make_pair(make_pair(s.x, s.y), 0));
				while (!qq.empty()) {
					pair<pair<int, int>, int> p = qq.front(); qq.pop();
					if (p.first.first == i && p.first.second == j) {
						dis[i][j] = p.second;
						break;
					}
					for (int k = 0; k < 4; k++) {
						int nx = p.first.first + dx[k], ny = p.first.second + dy[k];
						if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1 || Map[nx][ny] > s.sz || chk[nx][ny]) continue;
						chk[nx][ny] = 1;
						qq.push(make_pair(make_pair(nx, ny), p.second + 1));
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dis[i][j] != 0 && dist > dis[i][j]) {
					dist = dis[i][j];
				}
			}
		}
	return dist == 1000000 ? 0 : 1;
}

int main(void) {
	int sx, sy, t;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &Map[i][j]);
			if (Map[i][j] == 9) {
				sx = i; sy = j;
				Map[i][j] = 0;
			}
		}
	}
	t = 0;
	struct shark s(sx,sy,2,0);
	while (poss(s) && bfs(s)) {
		int dist, nt, rx, ry;
		
		dist = 1000000;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dis[i][j] != 0 && dist > dis[i][j]) {
					rx = i, ry = j; dist = dis[i][j];
				}
			}
		}
		
		s = shark(rx, ry, s.sz, s.c + 1);
		if (s.sz == s.c) 
			s = shark(rx, ry, s.sz + 1, 0);
		t += dist;
		Map[rx][ry] = 0;
	}
	printf("%d\n", t);
	return 0;
}