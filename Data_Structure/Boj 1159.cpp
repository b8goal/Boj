#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <functional>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <cmath>
#include <map>
#include <stack>
#define C 10
using namespace std;

typedef long long ll;
const int INF = 100000000;
const int MOD = 1000000007;
const int MAXN = 4000;

int abs(int x) { return x > 0 ? x : -x; }
int chk[26];
int main(void) {
	set<string> s;
	string str;
	int n, flag = 0;
	cin >> n;
	while (n--) {
		cin >> str;
		s.insert(str);
	}
	for (auto it : s)
		chk[it[0] - 'a']++;
	for (int i = 0; i < 26; i++)
		if (chk[i] >= 5)
			cout << char(i + 'a'), flag = 1;
	if (!flag) cout << "PREDAJA" << '\n';
	return 0;
}