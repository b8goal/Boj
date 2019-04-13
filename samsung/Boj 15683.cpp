#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int a[8][8], b[8][8], d[9], chk[8], dx[] = { 0,-1,0,1 }, dy[] = { 1,0,-1,0 };
int n, m, mn, cnt;
vector<pair<int, int> > cc;

void check(int no, int k) {
	for (int i = 1; i <= 8; i *= 2) {
		int x = cc[no].first, y = cc[no].second;
		if (k & i) {
			while (1) {
				x += dx[d[i]], y += dy[d[i]];
				if (x<0 || x>n - 1 || y<0 || y>m - 1 || b[x][y] == 6) break;
				b[x][y] = k;
			}
		}
	}
}
void f(int num) {
	if (num == cc.size()) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				b[i][j] = a[i][j];
		for (int i = 0; i < num; i++)
			check(i,chk[i]);
		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!b[i][j])
					cnt++;
		mn = min(mn, cnt);
		return;
	}
	int x = cc[num].first, y = cc[num].second;
	if (a[x][y]== 1) {
		for (int i = 1; i <= 8; i *= 2) {
			chk[num] = i;
			f(num + 1);
			chk[num] = 0;
		}
	}
	else if (a[x][y] == 2) {
		chk[num] = 5;
		f(num + 1);
		chk[num] = 10;
		f(num + 1);
		chk[num] = 0;
	}
	else if (a[x][y] == 3) {
		for (int i = 3; i <= 12; i += 3) {
			chk[num] = i;
			f(num + 1);
			chk[num] = 0;
		}
	}
	else if (a[x][y] == 4) {
		for (int i = 1; i <= 8; i *= 2) {
			chk[num] = 15 - i;
			f(num + 1);
			chk[num] = 0;
		}
	}
	else if (a[x][y] == 5) {
		chk[num] = 15;
		f(num + 1);
		chk[num] = 0;
	}
}
int main(void) {
	d[1] = 0; d[2] = 1; d[4] = 2; d[8] = 3;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
			if (!a[i][j])
				cnt++;
			if (1 <= a[i][j] && a[i][j] <= 5)
				cc.push_back({ i,j });
		}
	mn = cnt;
	f(0);
	cout << mn << '\n';
}