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

int x, y;
int z;
int cal(int mid) {
	return ((double)(y + mid)*100 / (double)(x + mid));
}
int main(void) {
	int ans = -1;
	cin >> x >> y;
	z = ((double)y*100 / (double)x);
	int lo, hi;
	lo = 1; hi = 2000000001;
	if (z >= 99) {
		puts("-1");
		return 0;
	}
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (cal(mid) > z){
			hi = mid - 1;
			ans = mid;
		}
		else
			lo = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}