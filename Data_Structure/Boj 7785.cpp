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
#include <math.h>
#include <map>
#include <stack>
#define C 10
using namespace std;

const int INF = 100000000;
const int MOD = 45678;
const int MAXN = 100000;

int main(void) {
	int n;
	cin >> n;

	map<string, int,greater<string>> m;
	while (n--) {
		string s1, s2;
		cin >> s1 >> s2;
		if (s2 == "enter")
			m.insert({ s1,1 });
		else if (m.find(s1)->second && s2=="leave")
				m.erase(s1);
	}
	for (auto it : m) cout << it.first << '\n';
	return 0;
}