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
int p[100], sum[MAXN], cache[MAXN + 1][MAXN + 1];
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
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int min(int x, int y) { return x > y ? y : x; }
int max(int x, int y) { return x > y ? x : y; }
int a[64][64];
int n;
vector<char> v;
void go(int k, int sx, int sy, int ex, int ey) {
	//cout << k<<' '<<sx<< ' '<<sy<<' '<<ex<<' '<<ey<<' ' << '\n';
	//getchar();
	if (k == 1) {
		a[sx][sy]? v.push_back('1') : v.push_back('0');
		return;
	}

	int tmp = a[sx][sy], flag = 1;
	FOR(i, sx, ex+1) {
		FOR(j, sy, ey+1) {
			if (a[i][j] != tmp) {
				flag = 0;
				break;
			}
		}
	}
	if (!flag) {
		v.push_back('(');
		go(k / 2, sx, sy, sx + k / 2 - 1, sy + k / 2 - 1);
		go(k / 2, sx, sy + k / 2, ex - k / 2, ey);
		go(k / 2, sx + k / 2, sy, ex, ey - k / 2);
		go(k / 2, sx + k / 2, sy + k / 2, ex, ey);
		v.push_back(')');
	}
	else
	v.push_back(tmp+'0');
}
int main(void) {
	scanf("%d", &n);
	FOR(i, 1, n + 1)
		FOR(j, 1, n + 1)
		scanf("%1d", &a[i][j]);
	go(n, 1, 1, n, n);
	for (auto it : v)
		cout << it;
	return 0;
}