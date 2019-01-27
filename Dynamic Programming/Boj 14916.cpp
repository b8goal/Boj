#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
typedef long long ll;
using namespace std;
const int MOD = 9901;
const int INF = 0x7fffffff;
const int MAXN = 300;

int cache[100001];
int main(void) {
	memset(cache, -1, sizeof cache);
	int n, cnt = 0;
	scanf("%d", &n);
	cache[2] = cache[5] = 1;
	cache[4] = 2;
	for (int i = 6; i <= 100000; i++){
		if (cache[i - 2] != -1)
			cache[i] = cache[i - 2] + 1;
		if (cache[i - 5] != -1)
			cache[i] = min(cache[i], cache[i - 5] + 1);
	}
	printf("%d\n", cache[n]);
	return 0;
}