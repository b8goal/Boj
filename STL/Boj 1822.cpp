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
int p[1000001], a[100001];
string s[50];
ll cache[61][61];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int min(int x, int y) { return x > y ? y : x; }
int max(int x, int y) { return x > y ? x : y; }

int main(void) {
	set<int> st;
	int n, m, x;
	scanf("%d %d", &n, &m);
	REP(i, n) {
		scanf("%d", &x);
		st.insert(x);
	}
	REP(i, m) {
		scanf("%d", &x);
		if (st.find(x) != st.end()) {
			st.erase(st.find(x));
		}
	}
	printf("%d\n", st.size());
	for(auto it:st)
		printf("%d ", it);
	return 0;
}
