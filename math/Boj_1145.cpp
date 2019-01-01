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

int gcd(int a, int b) {
	return !b ? a : gcd(b, a%b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main(void) {
	int a[5], mn = INF;
	for (int i = 0; i < 5; i++) scanf("%d", &a[i]);
	int g = gcd(a[0], a[1]);
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			int g1 = lcm(a[i], a[j]);
			for (int k = j + 1; k < 5; k++) {
				int g2 = lcm(g1, a[k]);
				mn = min(mn, g2);
			}
		}
	}
	printf("%d\n", mn);
	return 0;
}