#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>

using namespace std;
const int INF = 987654321;
int n, ans = INF;
int Map[20][20], chk[20], arr[2][20];
void dfs(int k,int a,int b) {
	if (k > n) return;
	if (k == n && a >= 1 && b >= 1) {
		int mn1 = 0, mn2 = 0, dif;
		
		for (int x = 0; x < a; x++)
			for (int y = 0; y < a; y++) {
				if (x == y) continue;
				mn1 += Map[arr[0][x]][arr[0][y]];
			}
		for (int x = 0; x < b; x++)
			for (int y = 0; y < b; y++) {
				if (x == y) continue;
				mn2 += Map[arr[1][x]][arr[1][y]];
			}

		dif = mn1 - mn2 > 0 ? mn1 - mn2 : mn2 - mn1;
		ans = min(ans, dif);
		return;
	}
	arr[0][a] = k;
	dfs(k + 1, a + 1, b);
	arr[1][b] = k;
	dfs(k + 1, a, b + 1);
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> Map[i][j];
	dfs(0,0,0);
	cout << ans << '\n';
	return 0;
}