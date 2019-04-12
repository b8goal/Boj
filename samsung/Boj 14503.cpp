#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int a[55][55], dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
int n, m, r, c, d, cnt;

void f(int x, int y, int dir) {
	if (!a[x][y]) {
		a[x][y] = 2;
		cnt++;
	}
	for (int k = dir + 3; k < dir + 13; k += 3) {
		int nx = x + dx[k % 4], ny = y + dy[k % 4];
		if (nx >= 0 && nx < n&&ny >= 0 && ny < m && !a[nx][ny])
			f(nx, ny, k % 4);
	}
	if (a[x - dx[dir]][y - dy[dir]] == 2)
		f(x - dx[dir], y - dy[dir], dir);
	else if (a[x - dx[dir]][y - dy[dir]] == 1) {
		cout << cnt << '\n';
		exit(0);
	}
	return;
}

int main(void) {
	cin >> n >> m >> r >> c >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	
	f(r, c, d);
	cout << cnt << '\n';
	return 0;
}