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
int p[1000001], dp[1001][1001], Map[1001][1001], dx[3] = { 1,-1 }, a[10001];
ll cache[61][61];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int min(int x, int y) { return x > y ? y : x; }
int max(int x, int y) { return x > y ? x : y; }

int main(void) {
	string s;
	cin >> s;
	a[0] = 1;
	for (int i = 0; s[i]; i++) {
		if (s[i] == 'A')
			swap(a[0], a[1]);
		else if (s[i] == 'B')
			swap(a[1], a[2]);
		else
			swap(a[0], a[2]);
	}
	if (a[0]) puts("1");
	else if (a[1]) puts("2");
	else puts("3");
	return 0;
}