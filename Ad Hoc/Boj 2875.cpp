#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int i, n, m, k, team, cnt;
	cin >> n >> m >> k;
	team = cnt = 0;
	if (n >= m * 2) {
		team = m;
		cnt = n + m - m * 3;
		if (k - cnt <= 0)
			cout << team << '\n';
		else {
			for (i = 1; k - cnt - i * 3 > 0; i++);
			cout << team - i << '\n';
		}
	}
	else {
		team = n / 2;
		cnt = n + m - n / 2 * 3;
		if (k - cnt <= 0)
			cout << team << '\n';
		else {
			for (i = 1; k - cnt - i * 3 > 0; i++);
			cout << team - i << '\n';
		}
	}
	return 0;
}