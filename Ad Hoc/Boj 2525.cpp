#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int main(void) {
	int a, b, c, s;
	cin >> a >> b >> c;
	s = a * 3600 + (b+c) * 60 ;
	cout << s / 3600 % 24 << ' ' << s % 3600 / 60 << '\n';
	return 0;
}