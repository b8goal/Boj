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
#include <random>
#include <ctime>
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
const int MOD = 10007;
const int INF = 0x7fffffff;
const int MIN = -32768 * 101;
const int MAXN = 100000 + 1;
const long double PI = 3.141592653589793238462643383279502884197;
int p[100];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
long long abs(long long x, long long y) { return x - y > 0 ? x - y : y - x; }
long long gcd(long long x, long long y) { return y ? gcd(y, x%y) : x; }

int h[1000001];
int main(void) {
	int n, cnt, mx, cur;
	mx = cnt = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> h[i];
	cur = h[0];
	for (int i = 1; i < n; i++) {
		if (cur > h[i])
			cnt++;
		else{
			cur = h[i];
			mx = max(mx, cnt);
			cnt = 1;
		}
	}
	cur = h[n - 1];
	cnt = 1;
	for (int i = n-2; i >= 0; i--) {
		if (cur > h[i])
			cnt++;
		else{
			cur = h[i];
			mx = max(mx, cnt);
			cnt = 1;
		}
	}
	cout << mx << '\n';
	return 0;
}