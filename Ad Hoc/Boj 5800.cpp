#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int a[100];
int main(void) {
	int n, x, mx, mn, g, t;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		g = mx = 0; mn = 100;
		cin >> x;
		for (int j = 0; j < x; j++) {
			cin >> a[j];
			mn = min(mn, a[j]);
			mx = max(mx, a[j]);
		}
		sort(a, a + x);
		for(int j=0; j<x; j++)
			if (j)
				g = max(g, a[j] - a[j - 1]);
		cout << "Class " << i << '\n' << "Max " << mx<<", Min " << mn << ", Largest gap " << g<< '\n';
	}
	return 0;
}