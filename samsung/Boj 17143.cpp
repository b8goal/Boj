#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

struct Node {
	int x, y, s, d, z;
	Node(int x1, int y1, int s1, int d1, int z1) {
		x = x1; y = y1; s = s1; d = d1; z = z1;
	}
};

int n, m, k, ans;
int a[100][100], dx[] = { -1,1,0,0 },dy[]={ 0, 0, 1, -1 };
queue<Node> q[100][100], q1[100][100];
int main(void) {
	cin >> n>> m >> k;
	for (int i = 0; i < k; ++i) {
		int x, y, s, d, z;
		cin >> x >> y >> s >> d >> z;
		--x; --y; --d;
		q[x][y].push(Node(x, y, s, d, z));
	}
	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < n; ++i) {
			if (!q[i][j].empty()) {
				ans += q[i][j].front().z;
				q[i][j].pop();
				break;
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (!q[i][j].empty()) {
					Node p = q[i][j].front(); q[i][j].pop();
					if (!p.d || p.d == 1) {
						int dist = p.s % (2 * (n - 1));
						while (dist--) {
							int nx = p.x + dx[p.d];
							if (nx < 0) {
								p.d = 1;
								p.x = 1;
							}
							else if (nx > n - 1) {
								p.d = 0;
								p.x = n - 2;
							}
							else
								p.x = nx;
						}
						q1[p.x][p.y].push(Node(p.x, p.y, p.s, p.d, p.z));
					}
					else {
						int dist = p.s % (2 * (m - 1));
						while (dist--) {
							int ny = p.y + dy[p.d];
							if (ny < 0) {
								p.d = 2;
								p.y = 1;
							}
							else if (ny > m - 1) {
								p.d = 3;
								p.y = m - 2;
							}
							else
								p.y = ny;
						}
						q1[p.x][p.y].push(Node(p.x, p.y, p.s, p.d, p.z));
					}
				}
			}
		}
		for(int i=0; i<n; ++i)
			for (int j = 0; j < m; ++j) {
				if (q1[i][j].size() >= 1) {
					Node t = q1[i][j].front(); q1[i][j].pop();
					while (!q1[i][j].empty()) {
						Node tt = q1[i][j].front(); q1[i][j].pop();
						if (t.z < tt.z)
							t = tt;
					}
					q[i][j].push(t);
				}
			}

	}
	cout << ans << '\n';
	return 0;
}