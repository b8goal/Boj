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
const int MOD = 9901;
const int INF = 0x7fffffff;
const int MAXN = 300;
int p[1000], dp[250001], v[250001];
ll cache[61][61];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }

int main(void) {
	while (1) {
		int n, x, flag = 1;
		bool chk[50];
		memset(chk, 0, sizeof chk);
		scanf("%d", &n);
		if (!n)break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 6; j++) {
				scanf("%d", &x);
				chk[x] = 1;
			}
		}
		for(int i=1; i<=49; i++)
			if (!chk[i]) {
				puts("No");
				flag = 0;
				break;
			}
		if(flag)
		puts("Yes");
	}
	return 0;
}