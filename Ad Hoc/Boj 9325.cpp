#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int main(void) {
	int tc, c, o, x, y;
	cin >> tc;
	while (tc--) {
		cin >> c >> o;
		for (int i = 0; i < o; i++) {
			cin >> x >> y;
			c += x * y;
		}
		cout << c << '\n';
	}
	return 0;
}