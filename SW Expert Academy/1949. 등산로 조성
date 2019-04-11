#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int a[10][10], chk[10][10], dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
int n, k, mx;
vector<pair<int, int> > v;

void f(int x, int y, int cnt, int flag) {
	mx = max(mx, cnt);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1 || chk[nx][ny]) continue;
		if (a[nx][ny] < a[x][y]) {
			chk[nx][ny] = 1;
			f(nx, ny, cnt + 1, flag);
			chk[nx][ny] = 0;
		}
		if (flag && a[nx][ny] >= a[x][y] && a[nx][ny] - k < a[x][y]) {
			chk[nx][ny] = 1;
			int temp = a[nx][ny];
			a[nx][ny] = a[x][y] - 1;
			f(nx, ny, cnt + 1, 0);
			a[nx][ny] = temp;
			chk[nx][ny] = 0;
		}
	}
}
int main(void) {
	int t=0, tc;
	cin >> tc;
	while (tc--) {
		memset(chk, 0, sizeof chk);
		memset(a, 0, sizeof a);
		t++;
		v.clear();
		cin >> n >> k;
		int tmp = 0;
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				if (tmp < a[i][j]) {
					v.clear();
					tmp = a[i][j];
					v.push_back(make_pair(i,j));
				}
				else if(tmp==a[i][j])
					v.push_back(make_pair( i,j ));
			}
		mx = 0;
		for (auto it : v){
			chk[it.first][it.second] = 1;
			f(it.first, it.second, 1, 1);
			chk[it.first][it.second] = 0;
		}
		cout << "#" << t << " " << mx << '\n';
	}
	return 0;
}