#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long cache[51];
int main(void) {
	int n;
	cin >> n;
	cache[0] = cache[1] = 1;
	for (int i = 2; i <= 50; i++)
		cache[i] = 1;
	for (int i = 2; i <= 50; i++)
		cache[i] += cache[i - 1] + cache[i - 2];

	cout << cache[n]%MOD << '\n';
	return 0;
}