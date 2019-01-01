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
	int n;
	long long sum = 0, x, y;
	scanf("%d", &n);
	while (n--) {
		scanf("%lld", &x);
		v.push_back(x);
	}
	scanf("%lld", &y);
	for (auto it : v) {
		if (!it)continue;
		else if (it%y == 0) sum += (it / y)*y;
		else sum += ((it)/y+1)*y;
	}
	printf("%lld\n", sum);
	return 0;
}