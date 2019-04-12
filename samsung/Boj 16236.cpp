#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
	int x, y, c, sz;
	Node(int x1, int y1, int c1, int sz1) {
		x = x1; y = y1; c = c1; sz = sz1;
	};
};
int a[20][20],dist[20][20], d[] = { 1,-1,0,0,0,0,1,-1 };
int n, t, sx, sy, tx, ty, td;
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			cin >> a[i][j];
			if (a[i][j] == 9)
				sx = i, sy = j;
		}
	queue<Node> q;
	q.push(Node(sx, sy, 0, 2));
	while (!q.empty()) {
		Node p = q.front(); q.pop();
		bool f = false;
		memset(dist, 0, sizeof dist);
		queue<Node> qq;
		qq.push(p);
		dist[p.x][p.y] = 1;
		while (!qq.empty()) {
			Node pp = qq.front(); qq.pop();
			for (int k = 0; k < 4; k++) {
				int nx = pp.x + d[k], ny = pp.y + d[k + 4];
				if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1 || dist[nx][ny] || a[nx][ny] ==9 || a[nx][ny] > p.sz) continue;
				dist[nx][ny] = dist[pp.x][pp.y] + 1;
				qq.push(Node(nx, ny, pp.c, pp.sz));
			}
		}

		td = 987654321;

		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == p.x && j == p.y) continue;
				if (!a[i][j] || a[i][j] == 9 || !dist[i][j]) continue;
				if (a[i][j] < p.sz && td > dist[i][j]) {
					td = dist[i][j];
					tx = i;
					ty = j;
					f = true;
				}
			}
		}
		if (!f) break;
		t += td - 1;
		a[p.x][p.y] = 0;
		a[tx][ty] = 9;
		if (p.c + 1 == p.sz)
			q.push(Node(tx, ty, 0, p.sz + 1));
		else
			q.push(Node(tx, ty, p.c + 1, p.sz));
	}
	cout << t << '\n';
	return 0;
}