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
#include <cmath>
#include <map>
#include <stack>
#define C 10
using namespace std;

typedef long long ll;
const int INF = 100000000;
const int MOD = 1000000007;
const int MAXN = 4000;

int abs(int x) { return x > 0 ? x : -x; }
int a[1500][1500];
int main(void) {
	int n;
	long long dp[36];
	memset(dp, 0, sizeof dp);
	dp[0] = 1;
	for (int i = 1; i <= 35; i++) {
		for (int j = 0; j < i; j++) {
			dp[i] += dp[j]*dp[i - 1 - j];
		}
	}
	cin >> n;
	cout << dp[n];

	return 0;
}