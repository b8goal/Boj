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

int n;
int a[20], b[20];
int cache[101][20];

int go(int hp, int num) {
	if (hp <= 0 || num==n) return 0;
	int&ret = cache[hp][num];
	if (ret != -1) return ret;
	ret = go(hp, num + 1);
	if (hp - a[num] > 0)
		ret = max(ret, go(hp - a[num], num + 1) + b[num]);
	return ret;
}
int main(void) {
	scanf("%d", &n);
	memset(cache, -1, sizeof cache);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	printf("%d\n", go(100, 0));
	return 0;
}