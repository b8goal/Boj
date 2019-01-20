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
#include <deque>
#define C 10
using namespace std;

typedef long long ll;
const int INF = 987654321;
const int MOD = 1000000007;
const int MAXN = 101;

int n, k;
int a[100], b[100];
int cache[100001][100];

int go(int capacitiy, int item) {
	if (item == n) return 0;
	int& ret = cache[capacitiy][item];
	if (ret != -1) return ret;
	ret = go(capacitiy, item + 1);
	if (capacitiy >= a[item])
		ret = max(ret, go(capacitiy - a[item], item + 1) + b[item]);
	return ret;
}

int main(void) {
	scanf("%d %d", &n, &k);
	memset(cache, -1, sizeof cache);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &a[i], &b[i]);
	printf("%d\n", go(k, 0));
	return 0;
}