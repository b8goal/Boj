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
int p[1000001], dp[1001][1001], Map[1001][1001], dx[3] = { 1,-1 }, a[10001];
ll cache[61][61];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int min(int x, int y) { return x > y ? y : x; }
int max(int x, int y) { return x > y ? x : y; }

int main(void) {
	int n, cnt = 0;
	cin >> n;
	map<string, int> m;
	string s;
	while (n--) {
		cin >> s;
		if (!m.count(s))
			m.insert({ s,1 });
		else {
			int tmp = m.find(s)->second, sum = 0;
			for (auto i = m.begin(); i != m.end(); i++) {
				if (i->first != s)
					sum += i->second;
			}
			if (sum < tmp)
				cnt++;
			m.find(s)->second++;
		}
	}
	cout << cnt << '\n';
	return 0;
}