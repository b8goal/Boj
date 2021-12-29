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
#include <stack>
#define C 10
using namespace std;

const int INF = 1000000000;
const int MOD = 998244353;
const int MAXN = 100000;

int main(void) {
	int n, ans = 0;
	stack<int> s;
	scanf("%d", &n);
	for (int i = 0,x; i < n; i++) {
		scanf("%d", &x);
		if (!x)
			s.pop();
		else
			s.push(x);
	}
	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}
	printf("%d\n", ans);
	return 0;
}