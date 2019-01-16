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
#include <cmath>
#include <map>
#include <stack>
#define C 10
using namespace std;

typedef long long ll;
const int INF = 100000000;
const int MOD = 1000000007;
const int MAXN = 4000;

int main(void) {
	int c, k, p, sum = 0;
	scanf("%d %d %d", &c, &k, &p);
	for (int i = 1; i <= c; i++) {
		sum += i * k + i * i*p;
	}
	printf("%d\n", sum);
	return 0;
}