#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int main(void) {
	int a, b, c, s, d;
	cin >> a >> b >> c >> d;
	s = a * 3600 + b * 60 + c + d;
	cout << s / 3600 % 24 <<' '<< s%3600 / 60 << ' '<<s % 60 << '\n';
	return 0;
}