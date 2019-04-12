#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int a[20][20], b[2][20], sum[2], cnt[2];
int n, mn;
vector<int> v;
int main(void) {
	cin >> n;
	mn = 987654321;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++)
		v.push_back(i < n / 2 ? 0 : 1);
	do {
		cnt[0] = cnt[1] = sum[0] = sum[1] = 0;
		for (int i = 0; i < n; i++)
			if (v[i])
				b[0][cnt[0]++] = i;
			else
				b[1][cnt[1]++] = i;
		for(int i=0; i<n/2;i++)
			for (int j = 0; j < n / 2; j++) {
				if (i == j)continue;
				sum[0] += a[b[0][i]][b[0][j]];
				sum[1] += a[b[1][i]][b[1][j]];
			}
		mn = min(mn, abs(sum[0] - sum[1]));
	} while (next_permutation(v.begin(), v.end()));
	cout << mn << '\n';
	return 0;
}