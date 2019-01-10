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

ll init(vector<ll>&a, vector<ll>&tree, int node, int start, int end) {
	if (start==end) return tree[node] = a[start];
	else return tree[node] = ((init(a, tree, node * 2, start, (start + end) / 2) % MOD)*(init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end) % MOD)) % MOD;
}

ll update(vector<ll>&tree, int index, int node, int start, int end, ll diff) {
	if (index<start || index>end) return tree[node];
	if (start == end) return tree[node] = diff;
	return tree[node] = ((update(tree, index,node * 2, start, (start + end) / 2,diff) % MOD)*(update(tree, index, node * 2 + 1, (start + end) / 2 + 1, end,diff) % MOD)) % MOD;
}

ll mul(vector<ll> &tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 1;
	if (left <= start && end <= right) return tree[node];
	return ((mul(tree, node * 2, start, (start + end) / 2, left, right) % MOD)*(mul(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right) % MOD)) % MOD;
}
int main(void) {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	m += k;
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<ll>tree(tree_size);
	vector<ll>a(n);
	
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	init(a, tree, 1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		int t1;
		scanf("%d", &t1);
		if (t1 == 1) {
			int t2;
			ll t3;
			scanf("%d %lld", &t2, &t3);
			update(tree, t2-1, 1, 0, n - 1, t3);
		}
		if (t1 == 2) {
			int t2, t3;
			scanf("%d %d", &t2, &t3);
			printf("%lld\n", mul(tree, 1, 0, n - 1, t2 - 1, t3 - 1)%MOD);
		}
	}
	return 0;
}