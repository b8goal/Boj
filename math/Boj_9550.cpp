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
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, k, sum = 0;
		scanf("%d %d", &n, &k);
		for (int i = 0,x; i < n; i++) {
			scanf("%d", &x);
			sum += x / k;
		}
		printf("%d\n", sum);
	}
	return 0;
}