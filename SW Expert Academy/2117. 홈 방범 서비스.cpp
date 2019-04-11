#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int a[20][20], chk[20][20];
int n, m, mx, mxcnt;

void check(int x, int y, int k) {
	int cnt = 0;
	for (int i = x - (k - 1); i < x + k; i++) {
		for (int j = y - cnt; j <= y + cnt; j++) {
			if (i<0 || i>n - 1 || j<0 || j>n - 1) continue;
			chk[i][j] = 1;
		}
		cnt += (i < x ? 1 : -1);
	}
}

int cal(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (chk[i][j] && a[i][j])
				cnt++;
		}
	}
	return cnt;
}

void p_map() {
	puts("");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << chk[i][j];
		}puts("");
	}getchar();
}
int main(void) {
	int tc, t = 0;
	cin >> tc;
	while (tc--) {
		mx = -987654321;
		t++;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 1; k <= 40; k++){
					memset(chk, 0, sizeof chk);
					check(i, j, k);
					int tmp = cal(i, j);
					if ( tmp*m - (k * k + (k - 1)*(k - 1)) >= 0)
						mx = max(mx, tmp);
				}
			}
		}
		cout << "#" << t << " " << mx << '\n';
	}
	return 0;
}