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

int gcd(int a, int b) {
	if (b) return gcd(b, a%b);
	else return a;
}

int main(void) {
	int n, m;
	char c;
	scanf("%d%c%d", &n, &c, &m);
	printf("%d%c%d\n", n/gcd(n,m), c, m / gcd(n, m));
	return 0;
}