#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int n, m, t, cnt, ans;
int a[50][50], d[] = { 0,-1,0,1,1,0,-1,0 }, pos[2], tmp[50][50];


void f(int x, int y, int dir,int t,int k) {
	int nt = tmp[x][y];
	if (tmp[x][y] == -1) return;
	tmp[x][y] = t;
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
			if (a[i][j] == -1) 
				pos[cnt++] = i;
		}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			tmp[i][j] = a[i][j];
	while (t--) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				a[i][j] = tmp[i][j];
		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < m; ++j){
				if (a[i][j] != -1 && a[i][j] != 0) {
					int count, amount;
					amount = a[i][j] / 5;
					for (int k = 0; k < 4; ++k) {
						int nx = i + d[k], ny = j + d[k + 4];
						if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1 || tmp[nx][ny] == -1) continue;
						tmp[i][j] -= amount;
						tmp[nx][ny] += amount;
					}
				}
			}
		for (int i = 0; i < 2; ++i)
			f(pos[i],1,0,0,i);
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j){
			if (tmp[i][j] == -1) continue;
			ans += tmp[i][j];
		}
	cout << ans << '\n';
	return 0;
}