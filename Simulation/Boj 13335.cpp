#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int a[1000], b[1000], chk[1050];
int n, w, l, t, cnt;

int main(void) {
	cin >> n >> w >> l;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int s = 0, cw = 0;
	while (++t) {
		for (int i = s; i < n; i++) {
			bool f = 0;
			//cout << t << ' ' << i<< ' '<< b[i] << ' ' << cw << '\n';
			if (!b[i] && cw + a[i] > l) break;
			if (!chk[b[i] + 1]) {
				chk[b[i] + 1] = 1;
				chk[b[i]] = 0;
				b[i]++;
				if (b[i] == 1)
					cw += a[i];
				f = 1;
			}
			if (chk[w + 1]) {
				chk[w + 1] = 0;
				cw -= a[i];
				s++;
			}
			if (!f) break;
		}

		if (s == n) break;
	}
	cout << t << '\n';
	return 0;
}