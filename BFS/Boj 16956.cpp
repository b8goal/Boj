#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

char a[501][501];
int chk[501][501], dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };

int main(void) {
	int r, c;
	queue<pair<int, int> > q;
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++){
			cin >> a[i][j];
			if (a[i][j] == 'S'){
				q.push(make_pair(i, j));
				chk[i][j] = 1;
			}
		}

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			if (a[i][j] == 'W') {
				for (int k = 0; k < 4; k++) {
					int ny = i + dx[k], nx = j + dy[k];
					if (ny<0 || ny>r - 1 || nx<0 || nx>c - 1 || a[ny][nx] != '.') continue;
					a[ny][nx] = 'D';
				}
			}
		}
	while (!q.empty()) {
		pair<int, int> p = q.front(); q.pop();
		if (a[p.first][p.second] == 'W') {
			cout << 0 << '\n';
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int ny = p.first + dx[i], nx = p.second + dy[i];
			if (ny<0 || ny>r - 1 || nx<0 || nx>c - 1 || chk[ny][nx] || a[ny][nx] == 'D') continue;
			chk[ny][nx] = 1;
			q.push(make_pair(ny, nx));
		}
	}
	cout << 1 << '\n';
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << a[i][j];
		}cout << '\n';
	}
	return 0;
}