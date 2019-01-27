#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
typedef long long ll;
using namespace std;
const int MOD = 9901;
const int INF = 0x7fffffff;
const int MAXN = 300;

int main(void) {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int Map[50][50], chk[50][50], dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
		int n, m, k, x, y, cnt = 0;
		memset(Map, 0, sizeof Map);
		memset(chk, 0, sizeof chk);
		queue<pair<int, int> > q;
		scanf("%d %d %d", &m, &n, &k);
		while (k--) {
			scanf("%d %d", &x, &y);
			Map[y][x] = 1;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (!chk[i][j] && Map[i][j]) {
					q.push({ i,j });
					++cnt;
					while (!q.empty()) {
						pair<int, int> p = q.front(); q.pop();
						chk[p.first][p.second] = 1;
						for (int k = 0; k < 4; k++) {
							int nx = p.first + dx[k], ny = p.second + dy[k];
							if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1 || chk[nx][ny] || !Map[nx][ny]) continue;
							chk[nx][ny] = 1;
							q.push({ nx,ny });
						}
					}
				}
			}
		printf("%d\n", cnt);
	}
	return 0;
}