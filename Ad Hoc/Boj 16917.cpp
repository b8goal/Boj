#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

int main(void) {
	int a, b, c, x, y, mn;
	cin >> a >> b >> c >> x >> y;
	mn = a * x + b * y;
	mn = min(mn, 2 * y*c + abs(x - y)*a);
	mn = min(mn, 2 * x*c + abs(x - y)*b);
	mn = min(mn, max(x, y) * 2 * c);
	cout << mn << '\n';
	return 0;
}