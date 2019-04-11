#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int a[8][8], chk[8][8], dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
int n, m, mx;
vector<pair<int, int> > v[2];

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
			if (!a[i][j]){
				v[0].push_back({ i,j });
			}
			if (a[i][j] == 2)
				v[1].push_back({ i,j });
		}

	for (int i = 0; i < v[0].size(); i++) {
		for (int j = i + 1; j < v[0].size(); j++) {
			for (int k = j + 1; k < v[0].size(); k++) {
				memset(chk, 0, sizeof chk);
				chk[v[0][i].first][v[0][i].second] = 1;
				chk[v[0][j].first][v[0][j].second] = 1;
				chk[v[0][k].first][v[0][k].second] = 1;

				queue<pair<int, int> > q;
				for (auto it : v[1])
					q.push({ it.first,it.second });
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second; q.pop();
					chk[x][y] = 1;
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k], ny = y + dy[k];
						if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1 || chk[nx][ny] || a[nx][ny] == 1) continue;
						chk[nx][ny] = 1;
						q.push({ nx,ny });
					}
				}
				int cnt = 0;
				for (int i = 0; i < n; i++)
					for (int j = 0; j < m; j++)
						if (!chk[i][j] && !a[i][j])
							cnt++;
				//cout << cnt << '\n';
				mx = max(cnt, mx);
			}
		}
	}	
	cout << mx << '\n';
	return 0;
}