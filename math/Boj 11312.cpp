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
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
const int MOD = 1e9 + 7;
const int INF = 0x7fffffff;
const int MIN = -32768 * 101;
const int MAXN = 100000 + 1;
const long double PI = 3.141592653589793238462643383279502884197;

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
int a[100], cache[1001][101], volume[101], need[101];
char name[100][21];
int n, m;


int go(int capacity, int item) {
	if (item == n) return 0;
	int& ret = cache[capacity][item];
	if (ret != -1) return ret;
	ret = go(capacity, item + 1);
	if (capacity >= need[item]) 
		ret = max(ret, go(capacity - need[item], item + 1) + need[item]);
	return ret;
}

void reconstruct(int capacity, int item, vector<char*>& picked) {
	if (item == n) return;
	if (go(capacity, item) == go(capacity, item + 1))
		reconstruct(capacity, item + 1, picked);
	else {
		picked.push_back(name[item]);
		reconstruct(capacity - volume[item], item + 1, picked);
	}
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", a*a / (b*b));
	}
	return 0;
}