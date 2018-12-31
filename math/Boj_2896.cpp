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

#define C 10
using namespace std;

const int INF = 987654321;
const int MOD = 998244353;
const int MAXN = 1001;

int main(void) {
	double a, b, c, i, j, k, x, y, z;
	cin >> a >> b >> c >> i >> j >> k;
	x = a / i;
	y = b / j;
	z = c / k;
	double mn = min({ x,y,z });
	printf("%lf %lf %lf\n", a - mn * i, b - mn * j, c - mn * k);
	return 0;
}