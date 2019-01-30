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
int p[1000001], dp[1001][1001], Map[1001][1001], dx[3] = { 1,-1 };
ll cache[61][61];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int min(int x, int y) { return x > y ? y : x; }
int max(int x, int y) { return x > y ? x : y; }

int prime(unsigned int n) {
	int a = 0;
	unsigned int i = 2;
	while (i <= (unsigned int)(sqrt(n))) {
		if (n%i == 0) {
			a = 1;
			break;
		}
		++i;
	}
	return a;
}
int main(void) {
	int tc, a;
	scanf("%d", &tc);
	unsigned int n;
	while (tc--) {
		scanf("%u", &n);
		if (!n || n == 1) {
			printf("%d\n", 2);
			continue;
		}
		for (unsigned int i = n; i < 4215000000; i++) {
			a = prime(i);
			if (!a) {
				printf("%u\n", i);
				break;
			}
		}
	}
	return 0;
}