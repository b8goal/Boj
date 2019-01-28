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
int main(void) {
	int n, m;
	ll sum, mx;
	sum = mx = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf("%d", &A[i]);
		sum += A[i];
		if (i+1 >= m) {
			mx = max(mx, sum);
			sum -= A[i - m+1];
		}
	}
	printf("%lld\n", mx);
	return 0;
}