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
const int MAXN = 100+1;
using namespace std;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int p[100], a[MAXN], sum[MAXN], cache[MAXN + 1][MAXN + 1];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int min(int x, int y) { return x > y ? y : x; }
int max(int x, int y) { return x > y ? x : y; }
int tc, n, m, x, y, cnt;

int main(void) {
	string s1, s2;
	cin >> s1 >> s2;
	bitset<100000> b1(s1);
	bitset<100000> b2(s2);
	cout << (b1&b2) << '\n';
	cout << (b1 | b2) << '\n';
	cout << (b1^b2) << '\n';
	cout << (~b1) << '\n';
	cout << (~b2) << '\n';
	return 0;
}