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

int n, m, mx = 1;
int a[500][500], cache[500][500], dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

int go(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= n) return 0;
	int& ret = cache[y][x];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (a[y][x] < a[ny][nx]){
			ret = max(ret, 1 + go(ny, nx));
		}
	}
	return ret;
}

int main(void) {
	scanf("%d", &n);
	memset(cache, -1, sizeof cache);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j){
			if (cache[i][j] == -1)
				mx = max(mx, go(i, j));
		}
	

	/*for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j) {
			printf("%2d ", cache[i][j]);
		}puts("");
	}*/
	printf("%d\n", mx);
	return 0;
}