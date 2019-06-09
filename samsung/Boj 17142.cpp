#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int a[55][55], b[55][55], chk[15], d[] = { 1,-1,0,0,0,0,1,-1 };
int n, m, mn, empty_cnt, cnt;
pair<int, int> pos[15];
void f(int k, int t) {
	if (t == m) {
		queue<pair<int, int> > q;
		int tmp = empty_cnt;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				b[i][j] = a[i][j];
		for (int i = 0; i < cnt; ++i) {
			if (!chk[i]) continue;
			b[pos[i].first][pos[i].second] = 1;
			q.push(pos[i]);
		}
		while (!q.empty()) {
			pair<int, int> p = q.front(); q.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = p.first + d[i], ny = p.second + d[i + 4];
				if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1) continue;
				if (b[nx][ny] == 0 || b[nx][ny] == -2) {
					if (!b[nx][ny])
						--tmp;
					b[nx][ny] = b[p.first][p.second] + 1;
					q.push({ nx,ny });
					if (mn != INF && mn <= b[nx][ny])
						return;
					if (!tmp) {
						mn = min(mn, b[nx][ny]);
						return;
					}
				}
			}
		}
		return;
	}
	for (int i = k; i < cnt; ++i) {
		if (chk[i]) continue;
		chk[i] = true;
		f(i + 1, t + 1);
		chk[i] = false;
	}
}
int main(void) {
	mn = INF;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j){
			cin >> a[i][j];
			if (a[i][j] == 2) {
				a[i][j] = -2;
				++empty_cnt;
				pos[cnt].first = i;
				pos[cnt++].second = j;
			}
			else if (a[i][j] == 1) {
				a[i][j] = -1;
			}
			else
				++empty_cnt;
		}
	empty_cnt -= cnt;
	if (!empty_cnt) {
		cout << 0 << '\n';
		exit(0);
	}
	f(0, 0);
	if (mn == INF)
		cout << -1 << '\n';
	else
		cout << mn - 1 << '\n';
	return 0;
}