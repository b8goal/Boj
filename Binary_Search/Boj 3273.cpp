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
	int n, x, cnt = 0;
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	scanf("%d", &x);
	sort(a, a + n);
	FOR(i,0,n-1) {
		int k,lo, hi, mid;
		lo = i + 1; hi = n - 1; k = a[i];
		while (lo <= hi) {
			mid = lo + (hi - lo) / 2;
			if (k + a[mid] == x) {
				++cnt;
				break;
			}
			else if (k + a[mid] < x)
				lo = mid + 1;
			else
				hi = mid - 1;
		}
	}
	printf("%d\n", cnt);
	return 0;
}