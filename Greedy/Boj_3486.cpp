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

int rev(int x) {
	int cnt, tmp;
	cnt = 0;
	tmp = x;
	while (tmp) {
		tmp /= 10;
		cnt++;
	}

	tmp = 0;
	while (cnt--) {
		tmp = tmp * 10 + x % 10;
		x /= 10;
	}
	return tmp;
}

int main(void) {
	int n;
	scanf("%d", &n);
	while (n--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", rev(rev(a) + rev(b)));
	}
	return 0;
}