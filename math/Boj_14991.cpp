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
#include <stack>
#define C 10
using namespace std;

const int INF = 1000000000;
const int MOD = 998244353;
const int MAXN = 100000;

int gcd(int a, int b) {
	return !b ? a : gcd(b, a%b);
}

int main(void) {
	int t, n = 0;
	string s;
	scanf("%d", &t);
	while (t) {
		s.push_back((t % 9)+'0');
		t /= 9;
	}
	for (int i = s.size() - 1; i >= 0; i--)
		printf("%c", s[i]);
	return 0;
}