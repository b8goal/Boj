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
int p[1000];
ll cache[61][61], a[1000001];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }

int main(void) {
	int n, m;
	while (1) {
		int x,cnt = 0;
		scanf("%d %d", &n, &m);
		if (!n && !m) break;
		memset(a, 0, sizeof a);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (int j = 0; j < m; j++) {
			scanf("%d", &x);
			if (binary_search(a, a + n, x))
				cnt++;
		}
		printf("%d\n", cnt);
	}
	
	return 0;
}