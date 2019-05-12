#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

int main(void) {
	int n, l, d, cnt = 1;
	cin >> n >> l >> d;
	while (n*(l + 5)-5 >= d * cnt) {
		if ((d*cnt) % (l + 5) >= l && (d*cnt) % (l + 5) < l + 5) {
			cout << d * cnt << '\n';
			return 0;
		}
		++cnt;
	}
	cout << d*(cnt++) << '\n';
	return 0;
}