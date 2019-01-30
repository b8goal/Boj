#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
typedef long long ll;
using namespace std;
const int MOD = 1000000;
const int INF = 0x7fffffff;
const int MAXN = 300;
int p[1000001], dp[1000001], dx[3] = { 1,-1};
ll cache[61][61];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int min(int x, int y) { return x > y ? y : x; }
int max(int x, int y) { return x > y ? x : y; }
int main(void) {
	int n;
	dp[0] = 1;
	for (int i = 1; i <= 1000000; i++)
		dp[i] = (dp[(int)floor(i - sqrt(i))]%MOD + dp[(int)floor(log(i))] % MOD + dp[(int)floor(i*sin(i)*sin(i))] % MOD) % MOD;
	while (1) {
		scanf("%d", &n);
		if (n == -1) break;
		printf("%d\n", dp[n]);
	}
	return 0;
}