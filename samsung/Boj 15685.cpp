#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int a[101][101], dy[] = { 0,-1,0,1 }, dx[] = { 1,0,-1,0 };
int main(void) {
	int n, cnt;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		vector<int> v;
		v.push_back(d);
		a[x][y] = 1;
		for (int j = 0; j < g; j++) {
			int len = v.size();
			for (int l = len-1; l >= 0; l--) {
				v.push_back((v[l] + 1) % 4);
			}
		}
		for (auto it : v) {
			x += dx[it]; y += dy[it];
			a[x][y] = 1;
		}
	}
	cnt = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1])
				cnt++;
	cout << cnt << '\n';
	return 0;
}