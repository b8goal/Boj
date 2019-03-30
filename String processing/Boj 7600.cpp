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
int p[901];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y % x ? gcd(y, x%y) : x; }

int main(void) {
	while (1) {
		string s;
		int chk[26], cnt;
		memset(chk, 0, sizeof chk);
		cnt = 0;
		getline(cin, s);
		if (s == "#") break;
		else {
			for (int i = 0; s[i]; i++) {
				if ('a' <= s[i] && s[i] <= 'z')
					chk[s[i] - 'a'] = 1;
				else if ('A' <= s[i] && s[i] <= 'Z')
					chk[s[i] - 'A'] = 1;
			}
		}
		for (int i = 0; i < 26; i++)
			if (chk[i])cnt++;
		cout << cnt << '\n';
	}
	return 0;
}