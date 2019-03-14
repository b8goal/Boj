#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <cmath>
#include <map>
#define mod 1000000007
#define INF 9876543210
using namespace std;
int  v[3][500];
int main(void) {
	int a, b, ans = 0;
	scanf("%d %d", &a, &b);
	for (int i = 0; i < b; i++)
		scanf("%d", &v[0][i]);
	v[1][0] = v[0][0];
	v[2][b - 1] = v[0][b - 1];
	for (int i = 1; i < b; i++) {
		v[1][i] = max(v[1][i - 1], v[0][i]);
		v[2][b-i-1] = max(v[2][b - i], v[0][b - 1 - i]);
	}
	for (int i = 1; i < b - 1; i++)
		ans += max(min(v[1][i], v[2][i])-v[0][i], 0);
	printf("%d\n", ans);
	return 0;
}
