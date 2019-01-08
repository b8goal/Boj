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

int update(vector<int>&tree, int index, int val, int node, int start, int end) {
	if (end < index || index < start) return tree[node];
	if (start == end) return tree[node] = val;
	return tree[node] = min(update(tree, index, val, node * 2, start, (start + end) / 2), update(tree, index, val, node * 2 + 1, (start + end) / 2 + 1, end));
}

int update1(vector<int>&tree, int index, int val, int node, int start, int end) {
	if (end < index || index < start) return tree[node];
	if (start == end) return tree[node] = val;
	return tree[node] = max(update1(tree, index, val, node * 2, start, (start + end) / 2), update1(tree, index, val, node * 2 + 1, (start + end) / 2 + 1, end));
}

int query1(vector<int>&tree, int node, int left, int right, int start, int end) {
	if (left > end || right < start) return -INF;
	if (start >= left && right >= end) return tree[node];
	return max(query1(tree, node * 2, left, right, start, (start + end) / 2), query1(tree, node * 2 + 1, left, right, (start + end) / 2 + 1, end));
}

int query(vector<int>&tree, int node, int left, int right, int start, int end) {
	if (left > end || right < start) return INF;
	if (start >= left && right >= end) return tree[node];
	return min(query(tree, node * 2, left, right, start, (start + end) / 2), query(tree, node * 2 + 1, left, right, (start + end) / 2 + 1, end));
}
int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int> tree(tree_size);
	vector<int> tree1(tree_size);
	for (int i = 1,x; i <= n; i++) {
		scanf("%d", &x);
		update(tree, i, x, 1, 1, n);
		update1(tree1, i, x, 1, 1, n);
	}
	for (int i = 0,x,y; i < m; i++) {
		scanf("%d %d", &x, &y);
		printf("%d %d\n", query(tree, 1, x, y, 1, n), query1(tree1, 1, x, y, 1, n));
	}
	return 0;
}