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

#define C 10
using namespace std;

const int INF = 1000000000;
const int MOD = 998244353;
const int MAXN = 10000;

int p[MAXN + 2];
pair<int,int> cost[MAXN + 2];

int find(int x) {
	return x ^ p[x] ? p[x] = find(p[x]) : x;
}
void merge(int x, int y) {
	p[find(y)] = find(x);
}
int main(void) {
	int n, m, k, ans = 0;
	for (int i = 0; i <= MAXN + 1; i++) p[i] = i;
	vector<vector<int> > Map;

	scanf("%d %d %d", &n, &m, &k);
	Map.resize(n + 1);
	for (int i = 0; i < n; i++) {
		scanf("%d", &cost[i].first);
		cost[i].second = i+1;
	}
	for (int i = 0, v, w; i < m; i++) {
		scanf("%d %d", &v, &w);
		if (find(v) != find(w))
			merge(v, w);
	}
	sort(cost, cost + n);
	cost[MAXN + 1].first = INF;
	cost[MAXN + 1].second = MAXN + 1;

	for (int i = 0; i < n; i++) {
		if (find(cost[MAXN+1].second) != find(cost[i].second)) {
			merge(cost[MAXN + 1].second, cost[i].second);
			ans += cost[i].first;
		}
	}
	if (ans <= k) printf("%d\n", ans);
	else puts("Oh no");
	return 0;
}