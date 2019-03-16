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

// 라인 2번
vector<string> a;
vector<int> b;
int main(void) {
	string s;
	cin >> s;
	int i, j;
	i = j = 0;
	for (; s[i]; i++) {
		if ((i + 1 < s.length()) && ('A' <= s[i] && s[i] <= 'Z') && ('a' <= s[i + 1] && s[i + 1] <= 'z')) {
			a.push_back(s.substr(i, 2));
			i++;
		}
		else if ('A' <= s[i] && s[i] <= 'Z')
			a.push_back(s.substr(i, 1));

		else
			b.push_back(s[i] - '0');
	}
	if (a.size() && !b.size())
		cout << s << '\n';
	else if (a.size() != b.size())
		puts("error");
	else
		for (int i = 0; i < a.size(); i++) {
			cout << a[i];
			if (b[i] != 1)
				cout << b[i];
		}
	return 0;
}