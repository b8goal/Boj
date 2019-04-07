#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int main(void) {
	int a, b,x, y;
	a = b = 0;
	for (int i = 0; i < 10; i++) {
		cin >> x >> y;
		a += y-x;
		b = max(b, a);
	}
	cout << b << '\n';
	return 0;
}