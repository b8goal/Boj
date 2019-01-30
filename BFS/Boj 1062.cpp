#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
typedef long long ll;
using namespace std;
const int MOD = 1000000;
const int INF = 0x7fffffff;
const int MAXN = 300;
int p[1000001], dp[1001][1001];
string s[50];
ll cache[61][61];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int min(int x, int y) { return x > y ? y : x; }
int max(int x, int y) { return x > y ? x : y; }
bool chk[26];
int n, m, cnt, mx, f;
vector<char> v;

void go(int k,int depth) {
	if (depth == m) {
		cnt = 0;
		for (int i = 0; i < n; i++) {
			f = 0;
			for (int j = 0; j < s[i].size(); j++) {
				if (!chk[s[i][j] - 'a']){
					f = 1;
					break;
				}
			}
			if (!f)cnt++;
		}
		mx = max(mx, cnt);
		return;
	}
	for (int i = k; i < 26; i++) {
		if (!chk[i]) {
			chk[i] = 1;
			go(i + 1,depth+1);
			chk[i] = 0;
		}
	}
	return;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	if (m < 5) {
		cout << 0 << '\n';
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	if (m == 26) mx = n;
	else if (m >= 5) {
		m -= 5;
		chk['a' - 'a'] = 1;
		chk['n' - 'a'] = 1;
		chk['t' - 'a'] = 1;
		chk['i' - 'a'] = 1;
		chk['c' - 'a'] = 1;
		go(0, 0);
	}
	
	cout << mx << '\n';
	return 0;
}
