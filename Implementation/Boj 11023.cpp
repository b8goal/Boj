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

string str;
int a, b;
int main(void) {
	int x, sum;
	sum = 0;
	while (scanf("%d", &x)>0) {
		sum += x;
	}
	printf("%d\n", sum);
	return 0;
}