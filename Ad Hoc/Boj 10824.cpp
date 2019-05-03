#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

long long len(long long num) {
	long long cnt = 0;
	while (num != 0) { cnt++; num /= 10; }
	return cnt;
}

int main() {
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << a * (long long)pow(10, len(b)) + b + c * (long long)pow(10, len(d)) + d << '\n';
	return 0;
}