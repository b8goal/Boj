#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int a[50][50], chk[13];
int n, m, mn;
vector<pair<int, int> > h, ck;

void f(int k, int num) {
	if (num == m) {
		int sum = 0;
		for (int i = 0; i < h.size(); i++) {
			int temp = 50*50;
			for (int j = 0; j < ck.size(); j++) {
				if (!chk[j]) continue;
				temp = min(temp,abs(h[i].first - ck[j].first) + abs(h[i].second - ck[j].second));
			}
			sum += temp;
		}
		mn = min(mn, sum);
		return;
	}
	for (int i = k; i < ck.size(); i++) {
		if (!chk[i]) {
			chk[i] = 1;
			f(i+1, num + 1);
			chk[i] = 0;
		}
	}
}
int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			cin >> a[i][j];
			if (a[i][j] == 1)
				h.push_back({ i,j });
			if (a[i][j] == 2)
				ck.push_back({ i,j });
		}
	mn = 987654321;
	f(0, 0);
	cout << mn << '\n';
	return 0;
}