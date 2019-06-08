#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, ans;
int a[2001];
set<int> b;
int main(void) {
	int left, right, mid, target;

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		target = a[i];
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			int std = a[j];
			left = 0; right = n - 1;
			while (left <= right) {
				mid = left + (right - left) / 2;
				if (std + a[mid] == target) {
					left = mid + 1;
					if (mid == i || mid == j) continue;
					b.insert(target);
				}
				else if (std + a[mid] < target) 
					left = mid + 1;
				else
					right = mid-1;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (auto it : b) {
			if (a[i] == it)
				++ans;
		}
	}
	cout << ans << '\n';
	return 0;
}