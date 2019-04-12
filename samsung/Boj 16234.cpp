#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int a[50][50], chk[50][50], avg[50*50], dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
int n, l, r, cnt;
queue<pair<int, int> > q;
int main(void) {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	while (1) {
		bool f = false;
		memset(chk, 0, sizeof chk);
		int tmp = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!chk[i][j]) {
					int sum, num;
					sum = num = 0;
					chk[i][j] = tmp;
					q.push({ i,j });
					while (!q.empty()) {
						int x, y; tie(x, y) = q.front(); q.pop();
						num++;
						sum += a[x][y];
						for (int k = 0; k < 4; k++) {
							int nx = x + dx[k], ny = y + dy[k];
							if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1 || chk[nx][ny] || abs(a[x][y] - a[nx][ny])<l || abs(a[x][y] - a[nx][ny])>r) continue;
							chk[nx][ny] = tmp;
							q.push({ nx,ny });
							f = true;
						}
					}
					avg[tmp++] = sum / num;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (chk[i][j])
					a[i][j] = avg[chk[i][j]];
			}
		}

		if (!f) {
			cout << cnt << '\n';
			break;
		}
		cnt++;
	}
	return 0;
}