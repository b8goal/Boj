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
#include <list>
#include <bitset>
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define REP(i,n) FOR(i,0,n) 
typedef unsigned long long ull;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 0x7fffffff;
const int MAXN = 100000 + 1;
using namespace std;
int p[100];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int min(int x, int y) { return x > y ? y : x; }
int max(int x, int y) { return x > y ? x : y; }
int pow(int x, int y) {
	if (y == 0) return 0;
	if (y == 1) return x;
	if (y % 2 == 0) {
		int ret = pow(x, y / 2);
		return ret = (ret * ret);
	}
	else {
		int ret = pow(x, (y - 1) / 2);
		return ret = ret * ret*x;
	}
}
vector<double> v;

int main(void) {
	int br, bc, dr, dc, jr, jc, mx1,mx2;
	cin >> br >> bc >> dr >> dc >> jr >> jc;
	mx1 = max(abs(jr - br), abs(jc - bc));
	mx2 = abs(dr - jr) + abs(dc - jc);
	printf("%s", mx1 == mx2 ? "tie": mx2 > mx1 ? "bessie" : "daisy");
	return 0;
}