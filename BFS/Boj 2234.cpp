#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int a[51][51],chk[51][51],b[51*51],c[51*51], dx[] = { 0,-1,0,1 }, dy[] = { -1,0, 1,0 };

int main(void) {
	int n, m, idx, num, mx, ans;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	num = mx = ans = 0;
	idx = 1;
	for(int i=0; i<n; i++){
		for (int j = 0; j < m; j++) {
			if (!chk[i][j]) {
				int cnt = 1;
				chk[i][j] = idx;
				queue<pair<int, int> > q;
				q.push({ i,j });
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second; q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k], ny = y + dy[k];
						if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1 || chk[nx][ny]) continue;
						if (a[x][y] & (1 << k)) continue;
						chk[nx][ny] = chk[x][y];
						cnt++;
						q.push({ nx,ny });
					}
				}
				b[idx++] = cnt;
			}
		}
	}
	cout << idx-1 << '\n';
	for (int i = 1; i < idx; i++) {
		mx = max(mx, b[i]);
	}
	cout << mx << '\n';

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k], y = j + dy[k];
				if (x<0 || x>n - 1 || y<0 || y>m - 1 || chk[i][j] == chk[x][y]) continue;
				ans = max(ans, b[chk[i][j]] + b[chk[x][y]]);
			}
		}
	}cout << ans << '\n';
	return 0;
}