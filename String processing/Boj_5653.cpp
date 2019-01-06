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
const int MAXN = 4000;

int main(void) {
	int n;
	scanf("%d", &n);
	while (n--) {
		string s1, s2, str;
		cin >> s1 >> s2;
		getline(cin, str);
		str.erase(str.begin());
		cout << str <<' '<< s1 << ' '<<s2 << '\n';
	}
	return 0;
}

