#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <functional>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <math.h>
#include <map>
#include <stack>
#define C 10
using namespace std;

const int INF = 100000000;
const int MOD = 45678;
const int MAXN = 4000;

int main(void) {
	int n;
	scanf("%d", &n);
	vector<int> v[4], ab, cd;

	for (int i = 0, x; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &x);
			v[j].push_back(x);
		}
	}
	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			ab.push_back(v[0][i] + v[1][j]);
			cd.push_back(v[2][i] + v[3][j]);
		}
	sort(cd.begin(), cd.end());

	long long ans = 0;
	for (auto iter : ab) {
		auto lo = lower_bound(cd.begin(), cd.end(), -iter);
		auto hi = upper_bound(cd.begin(), cd.end(), -iter);
		ans += hi - lo;
	}
	printf("%lld\n", ans);
	
	return 0;
}