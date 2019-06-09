#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int n, m, ans, empty_count, t;
int a[50][50], b[50][50], cnt[10], d[] = { 1,-1,0,0,0,0,1,-1 };
pair<int, int> v[10];
queue<pair<int, int> > q;
void f(int p, int qq) {
	if (qq == m) {
		int c = empty_count;
		
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				b[i][j] = a[i][j];
		while (!q.empty())q.pop();
		for (int i = 0; i < t; ++i) {
			if (cnt[i]) {
				q.push(v[i]);
				b[v[i].first][v[i].second] = 1;
			}
		}
		if (!c) {
			cout << 0 << '\n';
			exit(0);
		}
		while (!q.empty()) {
			pair<int, int> p = q.front(); q.pop();
			if (ans <= b[p.first][p.second]) return;
			for (int i = 0; i < 4; i++) {
				int nx = p.first + d[i], ny = p.second + d[i + 4];
				if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1 || b[nx][ny] != 0) continue;
				b[nx][ny] = b[p.first][p.second] + 1;
				q.push({ nx,ny });
				--c;
				if (!c) {
					ans = min(ans, b[nx][ny]);
					return;
				}
			}
		}
		return;
	}

	for (int i = p; i < t; ++i) {
		if (!cnt[i]) {
			cnt[i] = 1;
			f(i + 1, qq + 1);
			cnt[i] = 0;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ans = INF;
	cin >> n >> m;
	t = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j){
			cin >> a[i][j];
			if (a[i][j] == 1)
				a[i][j] = -1;
			else if (a[i][j] == 2){
				a[i][j] = 0;
				v[t].first = i;
				v[t++].second = j;
			}
			if (!a[i][j])
				++empty_count;
		}
	empty_count -= m;
	if (!empty_count) {
		cout << 0 << '\n';
		return 0;
	}
	f(0,0);
	if (ans == INF)
		cout << -1 << '\n';
	else
		cout << ans - 1 << '\n';
	return 0;
}