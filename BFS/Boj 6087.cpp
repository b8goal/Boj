#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
	int x, y, d;
	Node(int x1, int y1, int d1) {
		x = x1; y = y1; d = d1;
	};
};
char a[105][105];
int chk[4][105][105], dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
int n, m, mn;
vector<pair<int, int> > v;
int main(void) {
	mn = 987654321;;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++)
			if (a[i][j] == 'C')
				v.push_back(make_pair(i, j));
	}
	queue<Node> q;
	for (int i = 0; i < 4; i++) {
		int x = v[0].first + dx[i], y = v[0].second + dy[i];
		if (x<0 || x>n - 1 || y<0 || y>m - 1 || a[x][y] == '*')continue;
		chk[i][x][y] = 1;
		q.push(Node(x, y, i));
	}
	while (!q.empty()) {
		Node p = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = p.x + dx[i], ny = p.y + dy[i];
			if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1 || a[nx][ny] == '*') continue;
			if (chk[i][nx][ny] && chk[i][nx][ny] <= chk[p.d][p.x][p.y]) continue;
			chk[i][nx][ny] = (p.d == i ? chk[p.d][p.x][p.y] : chk[p.d][p.x][p.y] + 1);
			q.push(Node(nx, ny, i));
		}
	}
	for (int i = 0; i < 4; i++) {
		if (!chk[i][v[1].first][v[1].second])continue;
		mn = min(mn, chk[i][v[1].first][v[1].second]);
	}
	cout << mn-1<< '\n';
	return 0;
}