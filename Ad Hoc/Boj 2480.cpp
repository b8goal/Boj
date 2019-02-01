#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
typedef long long ll;
using namespace std;
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define REP(i,n) FOR(i,0,n) 
const int MOD = 1000000;
const int INF = 0x7fffffff;
const int MAXN = 300;
int p[1000001];
string s[50];
ll cache[61][61];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int min(int x, int y) { return x > y ? y : x; }
int max(int x, int y) { return x > y ? x : y; }

int main(void) {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (a == b && b == c)
		printf("%d\n", 10000 + a * 1000);
	else if (a != b && b != c && a != c)
		printf("%d\n", max({ a,b,c }) * 100);
	else
		printf("%d\n", 1000 + 100 * (a == b ? a : c));
	return 0;
}
