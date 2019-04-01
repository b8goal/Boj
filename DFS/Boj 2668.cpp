#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

int n, cnt, a[101], chk[101];

void f(int x, int y) {
	for (int i = 1; i <= n; i++) {
		x = a[x];
		if (x == y) {
			cnt++;
			chk[x]++;
			return;
		}
	}
}
int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) f(i, i);
	cout << cnt << '\n';
	for (int i = 1; i <= n; i++) if (chk[i])cout << i << '\n';
	return 0;
}