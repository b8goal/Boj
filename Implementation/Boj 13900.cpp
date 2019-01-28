#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
typedef long long ll;
using namespace std;
const int MOD = 9901;
const int INF = 0x7fffffff;
const int MAXN = 300;
int p[1000], A[100001];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
long long i, w, sw, sum, l;
int main(void) {
	long long n, s = 0;
	long long sum[100001];
	long long ans = 0;
	memset(sum, 0, sizeof sum);
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &sum[i]); 
		s += sum[i];
	}
	for (int i = 0; i < n; i++) {
		int k = s - sum[i];
		ans += sum[i] * k;
	}
	printf("%lld\n", ans/2);
	return 0;
}

