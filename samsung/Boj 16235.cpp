#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int a[10][10],b[10][10], chk[10][10], dx[] = { -1,-1,-1,0,1,1,1,0 }, dy[] = { -1,0,1,1,1,0,-1,-1 };
int n, m, k;
vector<pair<int,int> > v[10][10];
int main(void) {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			cin >> a[i][j];
			b[i][j] = 5;
		}
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v[x - 1][y - 1].push_back({ z,1 });
	}
	while (k--) {
		queue<pair<int, int> > q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int l = 0; l < v[i][j].size(); l++){
					if (b[i][j] - v[i][j][l].first >= 0) {
						b[i][j] -= v[i][j][l].first;
						v[i][j][l].first +=1;

					}
					else v[i][j][l].second = 0;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int len = v[i][j].size();
				if (!len) continue;
				for (int r = len-1; r >= 0; r--) {
					if (!v[i][j][r].second) {
						b[i][j] += v[i][j][r].first/2;
						v[i][j].erase(v[i][j].end()-1);
					}
					else if (v[i][j][r].second && v[i][j][r].first % 5 == 0)
						q.push({ i,j });
				}
			}
		}
		while (!q.empty()) {
			int x, y; tie(x, y) = q.front(); q.pop();
			for (int r = 0; r < 8; r++) {
				int nx = x + dx[r], ny = y + dy[r];
				if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1) continue;
				v[nx][ny].push_back({ 1,1 });
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				b[i][j] += a[i][j];
				sort(v[i][j].begin(), v[i][j].end());
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans += v[i][j].size();
	cout << ans << '\n';
	return 0;
}