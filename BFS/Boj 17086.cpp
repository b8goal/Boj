#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int a[50][50], chk[50][50], dx[] = { -1,-1,-1,0,1,1,1,0 }, dy[] = { -1,0,1,1,1,0,-1,-1 };
int n, m, mx, ans;
vector<pair<int, int> > v;
int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
			if (!a[i][j])
				v.push_back(make_pair(i, j));
		}

	for (int i = 0; i < v.size(); i++) {
		memset(chk, 0, sizeof chk);
		mx = 50 * 50;
		queue < pair<pair<int, int>, int> > q;
		q.push(make_pair(make_pair(v[i].first, v[i].second), 0));
		chk[v[i].first][v[i].second] = 1;
		while (!q.empty()) {
			pair<pair<int, int>, int> p = q.front(); q.pop();
			if (a[p.first.first][p.first.second]) {
				mx = min(mx, p.second);
			}
			for (int k = 0; k < 8; k++) {
				int nx = p.first.first + dx[k], ny = p.first.second + dy[k];
				if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1 || chk[nx][ny]) continue;
				chk[nx][ny] = 1;
				q.push(make_pair(make_pair(nx, ny), p.second + 1));
			}
		}
		ans = max(ans, mx);
	}
	cout << ans << '\n';
	return 0;
}