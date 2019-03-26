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
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y%x ? gcd(y, x%y) : x; }

int a[500001], b[2][500001];
int main(void) {
	int n, k, cnt;
	cin >> n >> k; // n : 수빈 k : 동생
	
	memset(a, -1, sizeof a);
	memset(b, -1, sizeof b);
	queue<int> q;

	a[k] = 0;
	cnt = 1;
	q.push(k);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (k + (cnt*(cnt+1))/2 <= 500000) {
			a[k + (cnt*(cnt + 1)) / 2] = a[cur] + 1;
			q.push(k + (cnt*(cnt + 1)) / 2);
			cnt++;
		}
	}

	b[0][n] = 0;
	queue<pair<int, int> > qq;
	qq.push(make_pair(n, 0));
	while (!qq.empty()) {
		pair<int,int> p = qq.front(); qq.pop();
		int cur = p.first, time = p.second;
		if (cur - 1 >= 0) {
			if (time % 2 == 0 && (b[1][cur - 1] == -1 || b[1][cur-1] > time+1)) {
				b[1][cur - 1] = time + 1;
				qq.push(make_pair(cur - 1, time + 1));
			}
			if (time % 2 == 1 && (b[0][cur - 1] == -1 || b[0][cur - 1] > time+1)) {
				b[0][cur - 1] = time + 1;
				qq.push(make_pair(cur - 1, time + 1));
			}
		}
		if (cur + 1 <= 500000) {
			if (time % 2 == 0 && (b[1][cur + 1] == -1 || b[1][cur + 1] > time+1)) {
				b[1][cur + 1] = time + 1;
				qq.push(make_pair(cur + 1, time + 1));
			}
			if (time % 2 == 1 && (b[0][cur + 1] == -1 || b[0][cur + 1] > time+1)) {
				b[0][cur + 1] = time + 1;
				qq.push(make_pair(cur + 1, time + 1));
			}
		}
		if (cur * 2 <= 500000) {
			if (time % 2 == 0 && (b[1][cur * 2] == -1 || b[1][cur *2] > time+1)) {
				b[1][cur*2] = time + 1;
				qq.push(make_pair(cur * 2, time + 1));
			}
			if (time % 2 == 1 && (b[0][cur * 2] == -1 || b[1][cur * 1] > time+1)) {
				b[0][cur*2] = time + 1;
				qq.push(make_pair(cur * 2, time + 1));
			}
		}
	}

	int mn = INF;
	for (int i = k; i <= 500000; i++) {
		if (a[i] != -1) {
			if (a[i] % 2 == 0 && a[i] >= b[0][i])
				mn = min(mn, a[i]);
			else if (a[i] % 2 == 1 && a[i] >= b[1][i])
				mn = min(mn, a[i]);
		}
	}
	if (mn == INF)
		cout << -1 << '\n';
	else
		cout << mn << '\n';
	return 0;
}