#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define MOD 10000
vector<pair<int, int> > myhash[10000 + 1];
int a[500000 + 1];

int f(int a, int idx) {
	int num = a % MOD;
	for (int i = 0; i < myhash[num].size(); i++) {
		if (myhash[num][i].first == a) {
			int tmp = myhash[num][i].second;
			myhash[num][i].second = idx;
			return tmp;
		}
	}
	myhash[num].push_back(make_pair(a, idx));
	return -2;
}
int main(void) {
	memset(a, -1, sizeof a);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
		cin >> a[i];
	for (int i = 0; i < k; i++) {
		int tmp = f(a[i], i);
		if (tmp != -2) a[tmp] = -1;
	}
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		if (a[i] != -1) {
			cout.width(8);
			cout.fill('0');
			cout << a[i] << '\n';
			cnt++;
			if (cnt == n) break;
		}
	}
	return 0;
}