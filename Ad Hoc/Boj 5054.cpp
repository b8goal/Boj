#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int a[20];
int main(void) {
	int tc, n, mn, mx, avg, x;
	cin >> tc;
	while (tc--) {
		mx = avg = 0;
		mn = 100;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x;
			avg += x;
			mn = min(mn, x);
			mx = max(mx, x);
		}
		avg /= n;
		cout << 2 * (mx - avg) + 2 * (avg - mn) << '\n';

	}
	return 0;
}