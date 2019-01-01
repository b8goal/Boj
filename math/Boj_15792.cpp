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
	int a, b;
	cin >> a >> b;
	cout << a / b << '.';
	a %= b;
	for (int i = 0; i < 1300; i++) {
		a *= 10;
		cout << a / b;
		a %= b;
		if (a == 0) break;
	}
	return 0;
}