#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
typedef long long ll;
using namespace std;
const int MOD = 9901;
const int INF = 0x7fffffff;
const int MAXN = 300;
int p[1000], a[6], b[7];
ll cache[61][61];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }

int main(void) {
	int tc, sum1, sum2;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		sum1 = sum2 = 0;
		for (int i = 0; i < 6; i++) scanf("%d", &a[i]);
		for (int i = 0; i < 7; i++) scanf("%d", &b[i]);
		sum1 = a[0] + 2 * a[1] + 3 * a[2] + 3 * a[3] + 4 * a[4] + 10 * a[5];
		sum2 = b[0] + 2 * b[1] + 2 * b[2] + 2 * b[3] + 3 * b[4] + 5 * b[5] + 10 * b[6];
		printf("Battle %d: ", t);
		if (sum1 > sum2)
			puts("Good triumphs over Evil");
		else if (sum1 < sum2)
			puts("Evil eradicates all trace of Good");
		else
			puts("No victor on this battle field");
	}
	return 0;
}