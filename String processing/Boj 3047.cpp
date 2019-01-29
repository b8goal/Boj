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
int p[1000001], dp[250001];
ll cache[61][61];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }

int main(void) {
	int k[3], a, b, c;
	string s;
	cin >> k[0] >> k[1] >> k[2] >> s;
	a = min(min(k[0], k[1]), k[2]);
	c = max(max(k[0], k[1]), k[2]);
	b = k[0] + k[1] + k[2] - a - c;
	for (auto it : s) {
		if (it == 'A')
			cout << a << ' ';
		else if (it == 'B')
			cout << b << ' ';
		else
			cout << c << ' ';
	}
	return 0;
}