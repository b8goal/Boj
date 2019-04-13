#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int dice[7], a[20][20], dx[] = { 0,0,0,-1,1 }, dy[] = { 0,1,-1,0,0 };
int n, m, x, y, k, d;

void move(int dir) {
	int tmp;
	if (dir == 4) { // 1 - 동 , 2 - 서, 3 - 북, 4 - 남
		tmp = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[6];
		dice[6] = dice[5];
		dice[5] = tmp;
	}
	if (dir == 3) {
		tmp = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[6];
		dice[6] = dice[2];
		dice[2] = tmp;
	}
	if (dir == 2) {
		tmp = dice[1];
		dice[1] = dice[3];
		dice[3] = dice[6];
		dice[6] = dice[4];
		dice[4] = tmp;
	}
	if(dir==1) {
		tmp = dice[1];
		dice[1] = dice[4];
		dice[4] = dice[6];
		dice[6] = dice[3];
		dice[3] = tmp;
	}
}
int main(void) {
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	while (k--) {
		cin >> d;
		int nx = x + dx[d], ny = y + dy[d];
		if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1) continue;
		move(d);
		x = nx; y = ny;
		if (!a[nx][ny])
			a[nx][ny] = dice[6];
		else {
			dice[6] = a[nx][ny];
			a[nx][ny] = 0;
		}
		cout << dice[1] << '\n';
	}
	return 0;
}