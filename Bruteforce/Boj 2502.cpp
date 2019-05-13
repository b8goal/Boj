#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

int a[31], b[31];
int main(void) {
	int d, k, A, B;
	cin >> d >> k;
	a[1] = b[2] = 1;
	for (int i = 3; i <= 30; i++) {
		a[i] = a[i - 1] + a[i - 2];
		b[i] = b[i - 1] + b[i - 2];
	}
	for (int i = 1; i <= 100000; i++) {
		if ((k - i * a[d]) % b[d] == 0) {
			A = i;
			B = (k - i * a[d]) / b[d];
			break;
		}
	}
	cout << A << '\n' << B << '\n';
	return 0;
}