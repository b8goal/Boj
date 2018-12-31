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
	int n, ans = 0;
	cin >> n;
	for (int i = 3; i <= n; i += 3) {
		for (int j = 3; j <= n; j += 3) {
			if (i + j < n)
				ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}