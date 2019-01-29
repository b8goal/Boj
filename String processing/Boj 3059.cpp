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
	int tc;
	cin >> tc;
	while (tc--) {
		int a[26], sum = 0;
		memset(a, 0, sizeof a);
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++)
			if (!a[s[i] - 'A'])
				a[s[i] - 'A'] = 1, cout << i << '\n';
		for (int i = 0; i < 26; i++)
			if (!a[i])
				sum += i + 'A';
		cout << sum << '\n';
	}
	return 0;
}