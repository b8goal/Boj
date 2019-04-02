#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

int a[202][202];
int p, q, r, s, cnt;
int main(void) {
	for (int i = 0; i < 4; i++) {
		cin >> p >> q >> r >> s;
		for (int j = p*2; j <= r*2; j++) {
			for (int k = q*2; k <= s*2; k++) {
				a[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < 200; i++)
		for (int j = 0; j < 200; j++)
			if (a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1])
				cnt++;
	cout << cnt/4 << '\n';
	return 0;
}