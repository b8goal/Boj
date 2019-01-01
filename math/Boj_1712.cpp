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
const int MOD = 45678;
const int MAXN = 100000;

int gcd(int a, int b) {
	return !b ? a : gcd(b, a%b);
}
vector<long long> v;
int main(void) {
	int a, b, c, ans;
	scanf("%d %d %d", &a, &b, &c);
	if (c - b <= 0) {
		puts("-1");
		return 0;
	}
	ans = a / (c - b);
	printf("%d\n", ans+1);
	return 0;
}