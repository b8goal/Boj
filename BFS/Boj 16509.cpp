#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
typedef long long ll;
using namespace std;
const int MOD = 1000000;
const int INF = 0x7fffffff;
const int MAXN = 300;
int p[1000001], dp[1001][1001], Map[10][9], chk[10][9];
int dx[] = { -2,-3, -3, -2, 2, 3, 3, 2 }, dy[] = { -3, -2, 2, 3, 3, 2, -2, -3 };
int ax[] = { 0,-1, -1, 0, 0, 1, 1, 0 }, ay[] = { -1,0, 0, 1, 1, 0, 0, -1 };
int bx[] = { -1,-2, -2, -1, 1, 2, 2, 1 }, by[] = { -2,-1, 1, 2, 2, 1, -1, -2 };
ll cache[61][61];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int min(int x, int y) { return x > y ? y : x; }
int max(int x, int y) { return x > y ? x : y; }


int main(void) {
	int r1, c1, r2, c2;
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
	queue<pair<int, int>>q;
	q.push({ r1,c1 });
	chk[r1][c1] = 1;
	while (!q.empty()) {
		pair<int, int> p = q.front(); q.pop();
		if (p.first == r2 && p.second == c2) {
			printf("%d\n", chk[r2][c2] - 1);
			return 0;
		}
		for (int k = 0; k < 8; k++) {
			int nx = p.first + ax[k], ny = p.second + ay[k];
			if (nx < 0 || nx>9 || ny < 0 || ny>8 || (nx == r2 && ny == c2)) continue;
			nx = p.first + bx[k]; ny = p.second + by[k];
			if (nx < 0 || nx>9 || ny < 0 || ny>8 || (nx == r2 && ny == c2)) continue;
			nx = p.first + dx[k]; ny = p.second + dy[k];
			if (nx < 0 || nx>9 || ny < 0 || ny>8 || chk[nx][ny]) continue;
			chk[nx][ny] = chk[p.first][p.second] + 1;
			q.push({ nx,ny });
		}
	}
	puts("-1");
	return 0;
}
