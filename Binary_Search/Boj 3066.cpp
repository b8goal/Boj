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
	scanf("%d", &tc);
	while (tc--) {
		int n, a[40001];
		vector<int> v;
		memset(a, 0, sizeof a);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) 
			scanf("%d", &a[i]);
		v.push_back(-INF);
		for (int i = 1; i <= n; i++) {
			if (v.back() < a[i])
				v.push_back(a[i]);
			else {
				auto pos = lower_bound(v.begin(), v.end(), a[i]);
				*pos = a[i];
			}
		}
		printf("%d\n", v.size() - 1);
	}
	return 0;
}