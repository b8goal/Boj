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

int main(void) {
	int n, cnt[10], b[10];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	vector<int> a(n);
	for (int i = 0; i < n; i++) a[i] = i + 1;
	do {
		int flag = 0;
		memset(cnt, 0, sizeof cnt);
		for (int i = n-1; i >= 0; i--) {
			for (int j = 0; j < i; j++) {
				if (a[j] > a[i])
					cnt[i]++;
			}
		}

		for (int i = 0; i < n; i++) {
			if (cnt[i] != b[a[i]-1]) {
				flag = 1;
				break;
			}
		}
		if (!flag) break;
	} while ((next_permutation(a.begin(), a.end())));
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	return 0;
}