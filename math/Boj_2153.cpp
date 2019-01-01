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
	for (int i = 2; i <= 2000; i++) {
		if (!p[i]) {
			p[i] = 1;
			for (int j = i * i; j <= 2000; j += i)
				p[j] = -1;
		}
	}
	p[1] = 1;

	int sum = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z')
			sum += s[i] - 'a' + 1;
		else sum += s[i] - 'A' + 27;
	}
	if (p[sum] == 1) puts("It is a prime word.");
	else puts("It is not a prime word.");
	return 0;
}