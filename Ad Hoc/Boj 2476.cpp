#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int main(void) {
	int tc, s, mx;
	mx = 0;
	cin >> tc;
	while (tc--) {
		int a, b, c;
		s = 0;
		cin >> a >> b >> c;
		if (a == b && b == c)
			s += 10000 + a * 1000;
		else if (a == b)
			s += 1000 + a * 100;
		else if (b == c)
			s += 1000 + b * 100;
		else if (a == c)
			s += 1000 + c * 100;
		else
			s += max({ a,b,c }) * 100;
		mx = max(mx, s);
	}
	cout << mx << '\n';
	return 0;
}