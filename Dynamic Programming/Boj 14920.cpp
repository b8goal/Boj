#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int i = 1;
	long long n, cur, next;
	cin >> n;
	cur = n;
	if (n == 1)
		cout << 1 << '\n';
	else
		while (1) {
			++i;
			next = cur % 2 == 0 ? cur / 2 : 3 * cur + 1;
			cur = next;
			if (next == 1) {
				cout << i << '\n';
				break;
			}
		}
	return 0;
}