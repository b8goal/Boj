#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int a[31], b, c;
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < 31; i++)
		a[i] = (1 << i);
	for (int i = 1; i < 31; i++) {
		if (n > a[i])
			n -= a[i];
		else {
			b = i;
			break;
		}
	}
	n--;
	for (int i = b - 1; i >= 0; i--) {
		if (n&a[i])
			cout << 7;
		else
			cout << 4;
	}
	return 0;
}