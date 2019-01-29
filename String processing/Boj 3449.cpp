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
	int tc, cnt;
	cin >> tc;
	while (tc--) {
		cnt = 0;
		string s1, s2;
		cin >> s1 >> s2;
		for (int i = 0; s1[i]; i++)
			if (s1[i] ^ s2[i])
				cnt++;
		cout << "Hamming distance is " << cnt << "." << '\n';
	}
	return 0;
}