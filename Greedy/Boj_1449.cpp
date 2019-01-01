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

int main(void) {
	int n, l, sum = 1;
	scanf("%d %d", &n, &l);
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	sort(v.begin(), v.end());

	for (int i = 0, t = 0; i < n; i++) {
		if (v[i] - v[t] >= l) {
			t = i;
			sum++;
		}
	}
	printf("%d\n", sum);
	return 0;
}