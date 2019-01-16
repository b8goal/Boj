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
int main(void) {
	set<string> s;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		for (int j = 1; j <= str.size(); j++) {
			s.insert(str.substr(i, j));
		}
	}
	cout << s.size() << '\n';
	return 0;
}