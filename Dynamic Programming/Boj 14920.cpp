#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int i = 1;
	long long n;
	cin >> n;
	while (n != 1) {
		++i;
		n = n % 2 == 0 ? n / 2 : 3 * n + 1;
	}
	cout << i << '\n';
	return 0;
}