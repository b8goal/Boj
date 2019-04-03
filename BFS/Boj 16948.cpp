#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int a[201][201], chk[201][201], dx[] = { -2,-2,0,0,2,2 }, dy[] = { -1,1,-2,2,-1,1 };
int n, r1, c1, r2, c2;
int main(void) {
	cin >> n >> r1 >> c1 >> r2 >> c2;

	queue<pair<int, int> > q;
	q.push(make_pair(r1, c1));
	chk[r1][c1] = 1;
	while (!q.empty()) {
		pair<int, int> p = q.front(); q.pop();
		if (p.first == r2 && p.second == c2) {
			cout << chk[r2][c2] - 1 << '\n';
			return 0;
		}
		for (int i = 0; i < 6; i++) {
			int nx = p.first + dx[i], ny = p.second + dy[i];
			if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1 || chk[nx][ny]) continue;
			chk[nx][ny] = chk[p.first][p.second] + 1;
			q.push(make_pair(nx, ny));
		}
	}
	cout << -1 << '\n';
	return 0;
}