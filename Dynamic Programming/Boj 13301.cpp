#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
long long a, b;
int main(void) {
	a = b = 2;
	cin >> n;
	for (int i = 0; i < n; i++)
		b += a, a = b - a;
	cout << b << '\n';
	
	return 0;
}