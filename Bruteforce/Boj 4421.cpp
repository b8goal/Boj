#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

int a[100][100], dp[100][100];
int main(void) {
	int n, x, mx;
	cin >> n >> x;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j], dp[i][j] = -100000;
	dp[0][0] = a[0][0];
	for (int i = a[0][0]; i <= 100; i++) {
		for(int j=0; j<n; j++)
			for(int k=0; k<n; k++)
				if (a[j][k] == i) {
					for (int l = -x; l <= x; l++) {
						if (j + l<0 || j + l>n - 1) continue;
						if (a[j + l][k] > a[j][k])
							dp[j + l][k] = max(dp[j + l][k], dp[j][k] + a[j + l][k]);
					}
					for (int l = -x; l <= x; l++) {
						if (k + l<0 || k + l>n - 1) continue;
						if (a[j][k + l] > a[j][k])
							dp[j][k + l] = max(dp[j][k + l], dp[j][k] + a[j][k + l]);
					}
				}
	}
	mx = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mx = max(mx, dp[i][j]);
	cout << mx << '\n';
	return 0;
}