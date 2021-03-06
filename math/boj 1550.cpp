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
typedef long long ll;
using namespace std;
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define REP(i,n) FOR(i,0,n) 
const int MOD = 1e9 + 7;
const int INF = 0x7fffffff;
const int MAXN = 300;
int p[1000001], a[1000001], cache[1001][3];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int min(int x, int y) { return x > y ? y : x; }
int max(int x, int y) { return x > y ? x : y; }

int main(void) {
	string s;
	cin >> s;
	int ret = 0, tmp;
	FOR(i, 0, s[i]) {
		if ('A' <= s[i] && s[i] <= 'F')
			tmp = s[i] - 'A' + 10;
		else
			tmp = s[i] - '0';
		ret = ret * 16 + tmp;
	}
	cout << ret << '\n';
	return 0;
}