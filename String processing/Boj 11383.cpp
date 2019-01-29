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
	int n, m;
	string s1[10], s2[10];
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s1[i];
	for (int i = 0; i < n; i++) cin >> s2[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; s1[i][j]; j++) {
			if (s1[i][j] != s2[i][2 * j] || s1[i][j] != s2[i][2 * j + 1]) {
				puts("Not Eyfa");
				return 0;
			}
		}
	}
	puts("Eyfa");
	return 0;
}