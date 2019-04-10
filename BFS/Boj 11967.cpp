#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int light[100][100], chk[100][100], dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
vector<int> v[100][100];

int main(void) {
	int n, m, ans;
	cin >> n >> m;
	while (m--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v[a - 1][b - 1].push_back((c - 1) * 100 + (d - 1));
	}
	queue<int> q;
	chk[0][0] = light[0][0] = 1;
	ans = 1;
	q.push(0);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		int x = cur / 100, y = cur % 100;
		for (auto it : v[x][y]) {
			int nx = it / 100, ny = it % 100;
			if (chk[nx][ny] || light[nx][ny]) continue;
			light[nx][ny] = 1;
			ans++;
			bool f = 0;
			for (int i = 0; i < 4; i++) {
				int nnx = nx + dx[i], nny = ny + dy[i];
				if (nnx<0 || nnx>n - 1 || nny<0 || nny>n - 1 || !chk[nnx][nny]) continue;
				f = 1;
				break;
			}
			if (f) {
				chk[nx][ny] = 1;
				q.push(it);
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1 || chk[nx][ny] || !light[nx][ny]) continue;
			chk[nx][ny] = 1;
			q.push(nx * 100 + ny);
		}
	}
	cout << ans << '\n';
	return 0;
}