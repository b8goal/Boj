
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
int p[1000001], dp[1001][1001], Map[10][9], chk[10][9], dx[8] = { -2,-3,-3,-2,2,3,3,2 }, dy[8] = { -3,-2,2,3,3,2,-2,-3 };
ll cache[61][61];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int min(int x, int y) { return x > y ? y : x; }
int max(int x, int y) { return x > y ? x : y; }


int main(void) {
	int a[9], sum = 0;
	for (int i = 0; i < 9; i++)
		scanf("%d", &a[i]), sum += a[i];
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - a[i] - a[j] == 100) {
				for (int k = 0; k < 9; k++) {
					if (i==k || j==k) continue;
					printf("%d\n", a[k]);
				}
				return 0;
			}
		}
	}
	return 0;
}