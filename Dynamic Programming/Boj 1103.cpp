#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

char a[55][55];
int cache[55][55], p[55][55], chk[55][55], dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
int n, m;

int f(int x, int y) {
	if (x<0 || x>n - 1 || y<0 || y>m - 1 || a[x][y] == 'H') return 0;
	if (p[x][y]) { puts("-1"); exit(0); }
	int& ret = cache[x][y];
	if (chk[x][y]) return ret;
	p[x][y] = chk[x][y] = 1;
	for (int i = 0; i < 4; i++)
		ret = max(ret, f(x + (a[x][y] - '0')*dx[i], y + (a[x][y] - '0')*dy[i]));
	p[x][y] = 0;
	return ++ret;
}
int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << f(0, 0) << '\n';
	return 0;
}