#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int main(void) {
	int n, m;
	int a[101];
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		a[i] = i;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		for (int j = x, cnt = 0; j <= (x+y)/2; cnt++, j++)
			swap(a[j], a[y - cnt]);
	}
	for (int i = 1; i <= n; i++)
		cout << a[i] << ' ';
	return 0;
}