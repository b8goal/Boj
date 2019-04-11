#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int a[11], b[4];
int n, mx, mn;

void f(int num, int s) {
	if (num == n-1) {
		mx = max(mx, s);
		mn = min(mn, s);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (b[i]) {
			b[i]--;
			if (!i)
				f(num + 1, s + a[num + 1]);
			if (i == 1)
				f(num + 1, s - a[num + 1]);
			if (i == 2)
				f(num + 1, s*a[num + 1]);
			if (i == 3)
				f(num + 1, s / a[num + 1]);
			b[i]++;
		}
	}
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < 4; i++)
		cin >> b[i];
	mx = -0x7fffffff;
	mn = 0x7fffffff;
	f(0, a[0]);
	cout << mx << '\n' << mn << '\n';
	return 0;
}