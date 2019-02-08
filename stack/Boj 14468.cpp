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
double max(double x, double y) { return x > y ? x : y; }
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
int state[26];
char s[53], st[53];
int c[26], ans;

/*
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	for (int i = 0, cur = 0; i < 52; ++i) {
		if (c[s[i] - 'A'] == 0) {
			st[++cur] = s[i];
			c[s[i] - 'A'] = 1;
		}
		else if (st[cur] == s[i]) {
			cur--;
		}
		else {
			int j = 1;
			cout << s[i] << ' ';
			for (; j < cur && st[j] != s[i]; ++j);
			ans += cur - j;
			cout << s[j] << '\n';
			for (; j < cur; ++j) st[j] = st[j + 1];
			cur--;
		}
	}
	cout << ans;
	return 0;
}
*/



int main(void) {
	int cnt, ans;
	string str;
	cin >> str;
	cnt = ans = 0;
	stack<char> s1, s2;
	for (int i = 0; i< sz(str); i++) {
		if (!state[str[i] - 'A']){
			state[str[i] - 'A']++;
			s1.push(str[i]);
		}
		else {
			if (s1.top() == str[i])
				s1.pop();
			else {
				while (s1.top() != str[i]) {
					s2.push(s1.top()); s1.pop();
				}
				s1.pop();
				ans += sz(s2);
				while (!s2.empty()) {
					s1.push(s2.top()); s2.pop();
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
