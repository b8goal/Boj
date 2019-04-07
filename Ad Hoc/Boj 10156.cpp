#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int main(void) {
	int k, n, m;
	cin >> k >> n >> m;
	if (k*n >= m)
		cout << k * n - m << '\n';
	else
		cout << 0 << '\n';
	return 0;
}