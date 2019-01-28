#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
typedef long long ll;
using namespace std;
const int MOD = 9901;
const int INF = 0x7fffffff;
const int MAXN = 300;
int p[1000];
ll cache[61][61], a[31];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
long long i, w, sw, sum, l;
int main(void) {
	while (1) {
		string s;
		cin >> s;
		if (s == "#")
			break;
		int cnt = 0;
		for (int i = 0; s[i]; i++)
			if (s[i] == '1')
				cnt++;
		if (cnt % 2 == 0 && s[s.size() - 1] == 'e')
			s[s.size() - 1] = '0';
		else if (cnt % 2 == 0 && s[s.size() - 1] == 'o')
			s[s.size() - 1] = '1';
		else if (cnt % 2 == 1 && s[s.size() - 1] == 'o')
			s[s.size() - 1] = '0';
		else
			s[s.size() - 1] = '1';
		cout << s << '\n';
	}
	return 0;
}

