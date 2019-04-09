#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int n, mx, cnt;
int a[8], b[8];

void f(int num) {
	if (num == n){
		mx = max(mx, cnt);
		return;
	}
	if (a[num] <= 0 || cnt == n - 1) {
		f(num + 1);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (i == num || a[i] <= 0) continue;
		a[i] -= b[num];
		a[num] -= b[i];
		if (a[i] <= 0)cnt++;
		if (a[num] <= 0)cnt++;
		f(num + 1);
		if (a[i] <= 0)cnt--;
		if (a[num] <= 0)cnt--;
		a[i] += b[num];
		a[num] += b[i];
	}
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	f(0);
	cout << mx << '\n';
	return 0;
}