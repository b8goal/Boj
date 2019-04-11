#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int a[15], b[15];
int n, mx;

void f(int num, int s) {
	if (num > n) return;
	if (num == n) {
		mx = max(mx, s);
		return;
	}
	f(num + a[num], s + b[num]);
	f(num + 1, s);
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	f(0, 0);
	cout << mx << '\n';
	return 0;
}