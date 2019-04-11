#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

long long n, b, c, mn;
long long a[1000000];
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> b >> c;
	for (int i = 0; i < n; i++) {
		if (a[i] <= b)
			mn++;
		else
			mn += 1 + (a[i] - b) / c + ((a[i] - b) % c > 0 ? 1 : 0);
	}
	cout << mn << '\n';
	return 0;
}