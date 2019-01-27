#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
typedef long long ll;
using namespace std;
const int MOD = 9901;
const int INF = 0x7fffffff;
const int MAXN = 300;
//int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
int Map[100][100], dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
bool chk[100][100];
int n, mn, mx, cnt, ans;
int main(void) {
	mn = 100;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			scanf("%d", &Map[i][j]);
			mn = min(mn, Map[i][j]);
			mx = max(mx, Map[i][j]);
		}

	for (int k = mn-1; k <= mx; k++) {
		cnt = 0;
		queue<pair<int, int> > q;
		memset(chk, 0, sizeof chk);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (Map[i][j] <= k)
					chk[i][j] = 1;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!chk[i][j]) {
					chk[i][j] = 1;
					cnt += 1;
					q.push({ i,j });
					while (!q.empty()) {
						pair<int, int> p = q.front(); q.pop();
						for (int l = 0; l < 4; l++) {
							int nx = p.first + dx[l], ny = p.second + dy[l];
							if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1 || chk[nx][ny]) continue;
							chk[nx][ny] = 1;
							q.push({ nx,ny });
						}
					}
				}
			}
		}
		ans = max(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}