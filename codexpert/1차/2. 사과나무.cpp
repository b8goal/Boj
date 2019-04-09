#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

queue<pair<int, int>> q;
vector<pair<int, int> > v,f;
int a[10][10], chk[10][10], dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
int n, mx;
int bfs(void) {
	while (!q.empty()) {
		pair<int, int> p = q.front(); q.pop();
		chk[p.first][p.second] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = p.first + dx[i], ny = p.second + dy[i];
			if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1 || chk[nx][ny] || a[nx][ny] == 0) continue;
			q.push(make_pair(nx, ny));
			chk[nx][ny] = 1;
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 &&  !chk[i][j])
				cnt++;
		}
	}
	return cnt;
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			cin >> a[i][j];
			if (a[i][j] == 1)
				v.push_back(make_pair(i, j));
			if (a[i][j] == 2)
				f.push_back(make_pair(i, j));
		}

	
	for (int i = 0; i < f.size(); i++)
		q.push(make_pair(f[i].first, f[i].second));
	mx = max(mx, bfs());

	
	for (int i = 0; i < v.size(); i++) {
		memset(chk, 0, sizeof chk);
		chk[v[i].first][v[i].second] = 1;
		for (int j = 0; j < f.size(); j++)
			q.push(make_pair(f[j].first, f[j].second));
		mx = max(mx, bfs());
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			memset(chk, 0, sizeof chk);
			chk[v[i].first][v[i].second] = 1;
			chk[v[j].first][v[j].second] = 1;
			for (int k = 0; k < f.size(); k++)
				q.push(make_pair(f[k].first, f[k].second));
			mx = max(mx, bfs());
		}
	}

	mx=max(mx,bfs());
	cout << mx << '\n';

	return 0;
}