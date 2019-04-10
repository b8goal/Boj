#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int a[1000][1000], chk[1000][1000], dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };

int main(void) {
	int n, m, t, ans, mx;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	mx = t = 0;
	for(int i=0; i<n; i++)
		for (int j = 0; j < m; j++) {
			int cnt = 0;
			if (a[i][j]==1) {
				t++;
				queue<pair<int,int> > q;
				q.push({ i,j });
				chk[i][j] = t;
				cnt++;
				while (!q.empty()) {
					pair<int, int> p = q.front(); q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = p.first + dx[k], ny = p.second + dy[k];
						if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1 || chk[nx][ny] || !a[nx][ny]) continue;
						cnt++;
						chk[nx][ny] = t;
						q.push({ nx,ny });
					}
				}

				q.push({ i,j });
				chk[i][j] = t+1;
				a[i][j] = cnt;
				while (!q.empty()) {
					pair<int, int> p = q.front(); q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = p.first + dx[k], ny = p.second + dy[k];
						if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1 || !a[nx][ny]) continue;
						if (chk[nx][ny] == t) {
							chk[nx][ny] = t+1;
							a[nx][ny] = cnt;
							q.push({ nx,ny });
						}
					}
				}
			}
		}

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!a[i][j]) {
				map<int, int> mp;
				ans = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1 || !chk[nx][ny]) continue;
					mp[chk[nx][ny]] = a[nx][ny];
				}
				for (auto iter = mp.begin(); iter != mp.end(); iter++)
					ans += iter->second;
				mx = max(mx, ans);
			}
		}
	}
	cout << mx+1 << '\n';
	
	return 0;
}

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int a[1000][1000], chk[1000][1000],idx[1000000],pidx[1000000], dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };

int main(void) {
	int n, m, t, ans, mx;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	mx = t = 0;
	for(int i=0; i<n; i++)
		for (int j = 0; j < m; j++) {
			int cnt = 0;
			if (a[i][j]==1 && !chk[i][j]) {
				t++;
				queue<pair<int,int> > q;
				q.push({ i,j });
				chk[i][j] = t;
				cnt++;
				while (!q.empty()) {
					pair<int, int> p = q.front(); q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = p.first + dx[k], ny = p.second + dy[k];
						if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1 || chk[nx][ny] || !a[nx][ny]) continue;
						cnt++;
						chk[nx][ny] = t;
						q.push({ nx,ny });
					}
				}
				idx[t] = cnt;
			}
		}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!a[i][j]) {
				vector<int> v;
				ans = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1 || pidx[chk[nx][ny]]) continue;
					pidx[chk[nx][ny]] = 1;
					ans += idx[chk[nx][ny]];
					v.push_back(chk[nx][ny]);
				}
				mx = max(mx, ans);
				for (auto it : v)
					pidx[it] = 0;
			}
		}
	}
	cout << mx+1 << '\n';
	
	return 0;
}
#endif 