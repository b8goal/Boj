#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int a[1050][1050], chk[1050][1050], dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
int n, m, sx, sy;
int main(void) {
	cin >> n >> m;
	for(int i=0; i<n; i++)
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
			if (a[i][j] == 2)
				sx = i, sy = j;
		}
	queue<pair<int, int> > q;
	q.push({ sx,sy });
	chk[sx][sy] = 1;
	while (!q.empty()) {
		pair<int, int> p = q.front(); q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = p.first + dx[k], ny = p.second + dy[k];
			if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1 || chk[nx][ny] || !a[nx][ny]) continue;
			chk[nx][ny] = chk[p.first][p.second] + 1;
			q.push({ nx,ny });
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (chk[i][j])
				cout << chk[i][j] - 1 << ' ';
			else if (!a[i][j])
				cout << 0 << ' ';
			else if (a[i][j] && !chk[i][j])
				cout << -1 << ' ';

		}puts("");
	}
	return 0;
}