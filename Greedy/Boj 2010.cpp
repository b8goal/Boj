#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int main(void) {
	int n, s, x, y;
	cin >> n;
	s = 0;
	while (n--) {
		cin >> x;
		s += x - 1;
	}
	cout << s + 1 << '\n';
	return 0;
}