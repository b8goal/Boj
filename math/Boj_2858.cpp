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
const int MOD = 45678;
const int MAXN = 100000;

int gcd(int a, int b) {
	return !b ? a : gcd(b, a%b);
}

int p[2001];
int main(void){
	int r, b, l, w, sum = 0;
	scanf("%d %d", &r, &b);
	for (l = 1;; l++) {
		if (b%l == 0) w = b / l;
		sum = (l + 2)*(w + 2);
		if (sum == r + b) {
			printf("%d %d\n", l >= w ? l+2, w+2 : w+2, l+2);
			break;
		}
	}
	return 0;
}