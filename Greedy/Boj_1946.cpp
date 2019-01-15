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
#include <cmath>
#include <map>
#include <stack>
#define C 10
using namespace std;

typedef long long ll;
const int INF = 100000000;
const int MOD = 1000000007;
const int MAXN = 4000;

int main(void) {
	int tc, n;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		vector<pair<int, int> > v(n), ans;
		for(int i=0; i<n; i++)
			scanf("%d %d", &v[i].first, &v[i].second);
		
		sort(v.begin(), v.end());
		ans.push_back(make_pair(INF, INF));
		for (int i = 0; i < n; i++) {
			if (v[i].second < ans.back().second)
				ans.push_back(make_pair(v[i].first, v[i].second));
		}
		printf("%d\n", ans.size() - 1);
	}
	return 0;
}