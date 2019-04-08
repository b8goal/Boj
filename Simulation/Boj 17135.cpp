#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int a[20][20], b[20][20], chk[20][20], dx[] = { 0,-1,0 }, dy[] = { -1,0,1 };
int n, m, d, mx, cnt;
queue<pair<int, int> > q1;
void bfs(int x, int y) {
	memset(chk, 0, sizeof chk);
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(x, y), 0));
	chk[x][y] = 1;
	while (!q.empty()) {
		pair<pair<int, int>, int> p = q.front(); q.pop();
		if (b[p.first.first][p.first.second] == 1) {
			q1.push(make_pair(p.first.first, p.first.second));
			break;
		}
		for (int i = 0; i < 3; i++) {
			int nx = p.first.first + dx[i], ny = p.first.second + dy[i], nd = p.second + 1;
			if (nx<0 || nx>n || ny<0 || ny>m - 1 || abs(nx - x) + abs(ny - y) > d || chk[nx][ny]) continue;
			chk[nx][ny] = 1;
			q.push(make_pair(make_pair(nx, ny), nd));
		}
	}
}

void move(void) {
	while (!q1.empty()) {
		pair<int, int> p = q1.front(); q1.pop();
		if (b[p.first][p.second]) {
			cnt++;
			b[p.first][p.second] = 0;
		}
	}

	for (int j = 0; j < m; j++) {
		for (int i = n - 1; i >= 0; i--) {
			if (b[i][j] && i==n-1)
				b[i][j] = 0;
			if (i < n-1 && b[i][j] && !b[i + 1][j]) {
				b[i + 1][j] = 1;
				b[i][j] = 0;
			}
		}
	}
}
void copy_map(void) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			b[i][j] = a[i][j];
}

void print_map(void) {
	puts("");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << b[i][j];
		}puts("");
	}
	getchar();
}
int main(void) {
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	

	for(int i=0; i<m-2; i++)
		for(int j=i+1; j<m-1; j++)
			for (int k = j + 1; k < m; k++) {
				b[n][i] = b[n][j] = b[n][k] = 2;
				cnt = 0;
				copy_map();
				for (int l = 0; l <= n; l++) {
					bfs(n, i);
					bfs(n, j);
					bfs(n, k);
					move();

					//print_map();
					//cout << cnt << '\n';
				}
				mx = max(mx, cnt);
			}
	cout << mx << '\n';
	return 0;
}