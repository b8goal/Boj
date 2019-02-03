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
int tc,n, m, x, y;

int main(void) {
	list<pair<int,int>> l;
	scanf("%d", &n);
	REP(i, n)
		scanf("%d", &x), l.push_back({ x,i + 1 });
	list<pair<int, int>>::iterator it = l.begin();
	REP(i, n-1) {
		cout << it->second << ' ';
		int num = it->first;
		if (num > 0) {
			auto temp = it;
			++temp;
			if (temp == l.end())
				temp = l.begin();
			l.erase(it);
			it = temp;
			for (int i = 1; i < num; ++i) {
				++it;
				if (it == l.end())
					it = l.begin();
			}
		}
		else if (num < 0) {
			num = -num;
			auto temp = it;
			if (temp == l.begin())
				temp = l.end();
			--temp;
			l.erase(it);
			it = temp;
			for (int i = 1; i < num; ++i) {
				if (it == l.begin())
					it = l.end();
				--it;
			}
		}
	}
	cout << l.front().second << '\n';

	return 0;
}