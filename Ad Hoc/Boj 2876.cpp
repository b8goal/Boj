#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[100000];
int main(void) {
	int n, mx, mxidx, tmp, cnt;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	mx = mxidx = -1;
	for (int i = 1; i <= 5; i++) {
		tmp = i, cnt = 0;
		for (int j = 0; j < n; j++) {
			if (a[j].first == tmp || a[j].second == tmp) {
				cnt++;
			}
			else {
				if (mx < cnt) {
					mx = cnt;
					mxidx = tmp;
				}
				cnt = 0;
			}
		}
		if (mx < cnt) {
			mx = cnt;
			mxidx = tmp;
		}
	}
	
	cout << mx << ' ' << mxidx << '\n';
	return 0;
}