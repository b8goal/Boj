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
const int INF = 0x7fffffff;
const int MOD = 45678;
const int MAXN = 4000;

int update(vector<int> &tree, int index, int val, int node, int start, int end) {
	if (start > index || index > end) return tree[node];
	if (start == end) return tree[node] = val;
	return tree[node] = min(update(tree, index, val, node * 2, start, (start + end) / 2), update(tree, index, val, node * 2 + 1, (start + end) / 2 + 1, end));
}

int query(vector<int>&tree, int left, int right, int node, int start, int end) {
	if (left > end || right < start) return INF;
	if (left <= start && end <= right) return tree[node];
	return min(query(tree, left, right, node * 2, start, (start + end) / 2), query(tree, left, right, node * 2 + 1, (start + end) / 2 + 1, end));
}
int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int> tree(tree_size);

	for (int i = 1,a; i <= n; i++) {
		scanf("%d", &a);
		update(tree, i, a, 1, 1, n);
	}
	for (int i = 0,x,y; i < m; i++) {
		scanf("%d %d", &x, &y);
		printf("%d\n", query(tree, x , y , 1, 1, n ));
	}
	return 0;
}