#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

int a[1001], cache[1000];
int n;
int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], cache[i] = INF;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cache[i] = min(cache[i], cache[i - j] + a[j]);
	cout << cache[n] << '\n';
	return 0;
}