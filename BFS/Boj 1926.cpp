#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <functional>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <cmath>
#include <map>
#include <stack>
#define C 10
using namespace std;

typedef long long ll;
const int INF = 100000000;
const int MOD = 1000000007;
const int MAXN = 4000;
bool Map[500][500];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,1,-1 };

int main(void) {
	int n, m;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &Map[i][j]);
	int cnt, ans;
	ans = cnt = 0;
	queue<pair<int, int> >q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(Map[i][j]) {
				q.push(make_pair(i, j));
				++ans;
				int tmp = 0;
				while (!q.empty()) {
					pair<int, int> p = q.front(); q.pop();
					++tmp;
					Map[p.first][p.second] = false;
					for (int k = 0; k < 4; k++) {
						int nx = p.first + dx[k], ny = p.second + dy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m || !Map[nx][ny]) continue;
						q.push(make_pair(nx, ny));
						Map[nx][ny] = false;
					}
				}
				cnt = max(tmp, cnt);
			}
		}
	}
	printf("%d\n%d\n", ans, cnt);
	return 0;
}