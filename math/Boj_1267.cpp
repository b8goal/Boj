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
	int n, y, m, x;
	y = m = 0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		y += (x / 30 + 1) * 10;
		m += (x / 60 + 1) * 15;
	}
	if (y == m)printf("Y M %d\n", y);
	else if (y < m) printf("Y %d\n", y);
	else printf("M %d\n", m);
	return 0;
}