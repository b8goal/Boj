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

int main(void) {
	long long n,a,ans;
	scanf("%lld", &n);
	a = 2;
	for (long long i = 1; i <= n; i++)
		a = a * 2 - 1;
	printf("%lld\n", a*a);
	return 0;
}