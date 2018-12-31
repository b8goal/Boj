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
	return !b ? a : gcd(b, a%b);
}

int main(void) {
	bool a[300][300], b[300][300], c[300][300];
	memset(a, false, sizeof a);
	memset(b, false, sizeof b);
	memset(c, false, sizeof c);

	int n;
	scanf("%d", &n);
	for (int k = 0; k < 2; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (!k) scanf("%d", &a[i][j]);
				else scanf("%d", &b[i][j]);
			}

	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			for (int k = 0; k< n; k++) {
				if (a[i][k] * b[k][j]){
					c[i][j] = true;
					break;
				}
			}
		}
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (c[i][j]) ans++;
	printf("%d\n", ans);
	return 0;
}