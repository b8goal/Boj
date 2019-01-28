#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
typedef long long ll;
using namespace std;
const int MOD = 9901;
const int INF = 0x7fffffff;
const int MAXN = 300;
int p[1000], a[6], b[7];
ll cache[61][61];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;
	if (a == 60 && b == 60 && c == 60)
		puts("Equilateral");
	else if (a + b + c != 180)
		puts("Error");
	else if (a + b + c == 180 && a != b && b != c && a != c)
		puts("Scalene");
	else
		puts("Isosceles");
	return 0;
}