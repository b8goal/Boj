#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

int n, m, mx,an;
int weight[2000], value[2000];
int cache[10001][2000];

int f(int capacitiy, int item) {
	if (item == an) return 0;
	int& ret = cache[capacitiy][item];
	if (ret != -1)return ret;
	ret = f(capacitiy, item + 1);
	if (capacitiy >= weight[item]) {
		ret = max(ret, f(capacitiy - weight[item], item + 1) + value[item]);
	}
	return ret;
}
int main(void) {
	memset(cache, -1, sizeof cache);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int v, c, k;
		cin >> v >> c >> k;
		for (int j = 1; k > 0; j <<= 1) {
			int ix = min(j, k);
			weight[an] = v * ix; value[an++] = c * ix;
			k -= ix;
		}
	}
	cout << f(m, 0);
	return 0;
}