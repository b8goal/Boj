#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int INF = 0x7fffffff;
vector<int> v;

int main(void) {
	int n, x, ans = 0;
	scanf("%d", &n);
	v.push_back(-INF);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (v.back() < x) {
			v.push_back(x);
			ans++;
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), x);
			*it = x;
		}
	}
	printf("%d\n", ans);
	return 0;
}