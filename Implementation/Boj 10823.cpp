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
#include <deque>
#define C 10
using namespace std;

typedef long long ll;
const int INF = 987654321;
const int MOD = 1000000007;
const int MAXN = 101;

int main(void) {
	int x, sum, tc;
	char str[10005];
	sum = x = 0;
	while (scanf("%s",str) != EOF) {
		for (int i = 0; str[i]; i++) {
			if (str[i] == ',') {
				sum += x;
				x = 0;
			}
			else
				x = x * 10 + str[i] - '0';
		}
	}
	printf("%d\n", sum + x);
	return 0;
}