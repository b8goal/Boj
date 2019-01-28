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
	while (1) {
		ll a, b, c, d;
		cin >> a >> b >> c;
		if (!a && !b && !c) break;
		if (b - a == c - b)
			cout << "AP " << c + (b - a) << '\n';
		else
			cout << "GP " << c * (b / a) << '\n';
	}
	return 0;
}

