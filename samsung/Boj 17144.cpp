#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

struct Node {
	int x, y, d;
	Node(int x1, int y1, int d1) {
		x = x1; y = y1; d = d1;
	}
};
int n, m, t, cnt, ans;
int a[50][50], d[] = { 0,-1,0,1,1,0,-1,0 }, pos[2];
queue<Node> q;

void f(int x, int y, int dir,int t,int k) {
	int nt = a[x][y];
	if (a[x][y] == -1) return;
	a[x][y] = t;
	dir = dir % 4;
	int nx = x + d[dir], ny = y + d[dir + 4];
	if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1) {
		if (!k) {
			dir = (dir+1) % 4;
			nx = x + d[dir], ny = y + d[dir+4];
		}
		else {
			dir = (dir+3) % 4;
			nx = x + d[dir], ny = y + d[dir+4];
		}
	}
	f(nx, ny, dir, nt,k);
}

int main(void) {
	cin >> n >> m >> t;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			if (a[i][j] == -1) {
				pos[cnt++] = i;
			}
		}

	while (t--) {
		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < m; ++j) 
				if (a[i][j] != -1 && a[i][j] != 0) {
					int count, tmp;
					count = 0;
					tmp = a[i][j] / 5;
					for (int k = 0; k < 4; ++k) {
						int nx = i + d[k], ny = j + d[k + 4];
						if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1 || a[nx][ny] == -1) continue;
						++count;
					}
					for (int k = 0; k < 4; ++k) {
						int nx = i + d[k], ny = j + d[k + 4];
						if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1 || a[nx][ny] == -1) continue;
						q.push(Node(nx, ny, tmp));
					}
					q.push(Node(i, j, a[i][j] - count * tmp));
					a[i][j] = 0;
				}
		while (!q.empty()) {
			Node p = q.front(); q.pop();
			a[p.x][p.y] += p.d;
		}

		for (int i = 0; i < 2; ++i)
			f(pos[i],1,0,0,i);
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j){
			if (a[i][j] == -1) continue;
			ans += a[i][j];
		}
	cout << ans << '\n';
	return 0;
}