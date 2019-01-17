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

int main(void) {
	int e, s, m, k = 0;
	int a, b, c;
	a = b = c = 0;
	cin >> e >> s >> m;
	e--;
	s--;
	m--;
	while (1) {
		if (k % 15 == e && k % 28 == s && k % 19 == m) {
			cout << k+1 << '\n';
			return 0;
		}
		k++;
	}
	return 0;
}