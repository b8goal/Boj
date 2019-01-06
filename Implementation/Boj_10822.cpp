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
	string s;
	cin >> s;
	int tmp = 0, sum = 0;
	for (int i = 0; s[i]; i++) {
		if (s[i] == ',') {
			sum += tmp;
			tmp = 0;
			continue;
		}
		else 
			tmp = tmp * 10 + s[i] - '0';
	}
	cout << sum+tmp << '\n';
	return 0;
}

