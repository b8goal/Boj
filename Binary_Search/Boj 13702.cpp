#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

int n, k;
unsigned int a[10000];
unsigned int f(unsigned int x) {
	unsigned int cnt = 0;
	for (int i = 0; i < n; i++) 
		cnt += a[i] / x;
	return cnt;
}
int main(void) {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	unsigned int lo, hi, mid, mx, tmp;
	mx = -1;
	lo = 1; hi = (1 << 32) - 1;
	while (lo <= hi) {
		mid = lo + (hi - lo) / 2;
		tmp = f(mid);
		if (tmp < k) {
			hi = mid - 1;
		}
		else
			lo = mid + 1;
	}
	cout << hi << '\n';
	return 0;
}