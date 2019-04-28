#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <cmath>
#include <map>

#define INF 1000000
#define W 20
#define H 20
#define C 10

using namespace std;

int x, y, n;
int id[W][H], dist[C + 1][C + 1], vis[W][H], dp[C + 1][1 << C], dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
char Map[H][W+1];
pair<int, int> p[C + 1];


int go(int at, int mask) {
	if (dp[at][mask] > -1) return dp[at][mask];
	if (at&&mask == (1 << (n - 1)) - 1) return dp[at][mask] = 0;
	int i, cur, res = INF;
	for (int i = 1; i < n; i++) if (!(mask&(1 << (i - 1)))) {
		cur = dist[at][i] + go(i, mask | (1 << (i - 1)));
		if (res > cur)res = cur;
	}
	return dp[at][mask] = res;
}
void bfs(int no, int sx, int sy) {
	queue<pair<int, int> > q;
	q.push({ sx,sy });
	memset(vis, -1, sizeof vis);
	for (int i = 0; i < n; i++) dist[no][i] = INF;
	vis[sx][sy] = 0;
	while (!q.empty()) {
		int cx = q.front().first, cy = q.front().second; q.pop();
		int move = vis[cx][cy] + 1;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx<0 || nx>y - 1 || ny<0 || ny>x - 1 || vis[nx][ny] > -1 || Map[nx][ny] == 'x') continue;
			if (Map[nx][ny] != '.') dist[no][id[nx][ny]] = move;
			vis[nx][ny] = move;
			q.push({ nx,ny });
		}
	}
}
int pairwise(void) {
	for (int i = 0; i < n; i++) bfs(i, p[i].first, p[i].second);
	for (int i = 1; i < n; i++) for (int j = 0; j < i; j++) if (dist[i][j] == INF) return 0;
	return 1;
}
int main(void) {
	while (1) {
		n = 1;
		scanf("%d %d", &x, &y);
		if (x == 0 && y == 0) break;
		for (int i = 0; i < y; i++) scanf("%s", Map[i]);
		for (int i = 0; i < y; i++) for (int j = 0; j < x; j++) {
			if (Map[i][j] == 'o') p[0].first = i, p[0].second = j, id[i][j] = 0;
			else if (Map[i][j] == '*') p[n].first = i, p[n].second = j, id[i][j] = n++;
		}
		if (!pairwise()) puts("-1");
		else {
			memset(dp, -1, sizeof dp);
			printf("%d\n", go(0, 0));
		}
	}
	return 0;
}